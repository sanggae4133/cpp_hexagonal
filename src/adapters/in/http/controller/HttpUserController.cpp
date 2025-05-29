//
// Created by 125002 on 25. 5. 28.
//

#include "HttpUserController.hpp"

#include <iostream>
#include <regex>
#include <sstream>

using core::domain::model::User;
namespace aih = adapters::in::http;

aih::HttpUserController::HttpUserController(core::ports::in::IUserService& s): service_{s} {}

std::optional<aih::HttpResponse>

aih::HttpUserController::handle(const std::string& method, const std::string& endpoint, const std::string& body) {
    std::cout << "HTTP | mothod: " << method << ", endpoint: " << endpoint << ", body: " << body << std::endl;
    if (method=="GET" && endpoint=="/users")
    {
        auto v = service_.readUsers(); std::ostringstream o; o << '[';
        for (size_t i=0;i<v.size();++i){
            o << "{\"id\":"<<v[i].id<<",\"name\":\""<<v[i].name<<"\","<<"\"age\":"<<v[i].age<<"}";
            if (i+1<v.size()) o << ',';
        }   o << ']';
        return HttpResponse{200,o.str()};
    }
    if (method=="POST" && endpoint=="/users")
    {
        auto bodyName = body.find("name="), bodyAge = body.find("&age=");
        std::cout << bodyName << " " << bodyAge << std::endl;

        if (bodyName == 0 && bodyAge != std::string::npos){
            std::string name = body.substr(5,bodyAge - 5);
            int age=std::stoi(body.substr(bodyAge + 5));
            auto id=service_.createUser(name,age);
            return HttpResponse{201,"{\"id\":"+std::to_string(id)+'}'};
        }
        return HttpResponse{400,"{\"error\":\"bad body\"}"};
    }
    if (method=="DELETE")
    {
        std::smatch mch; std::regex re(R"(/users/(\d+))");
        if (std::regex_match(endpoint,mch,re)){
            bool ok=service_.deleteUser(std::stoull(mch[1]));
            return ok? HttpResponse{204,""} : HttpResponse{404,"{\"error\":\"not found\"}"};
        }
    }
    return std::nullopt;
}