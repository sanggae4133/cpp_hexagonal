//
// Created by 125002 on 25. 5. 29.
//

#include "SimpleHttpServer.hpp"

#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sstream>
#include <iostream>

namespace aih = adapters::in::http;

aih::SimpleHttpServer::SimpleHttpServer(int p, core::ports::in::IUserService& s)
    : port_{p}, ctrl_{s} {}

void aih::SimpleHttpServer::handle(int fd) {
    char buf[4096]{}; auto n = recv(fd,buf,sizeof(buf)-1,0);
    if (n<=0) return; std::string req(buf,n);
    std::istringstream ss(req); std::string method,path,vers;
    ss>>method>>path>>vers;
    std::string line; size_t len=0;
    while (std::getline(ss,line) && line!="\r")
        if (line.rfind("Content-Length:",0)==0) len = std::stoul(line.substr(15));
    std::string body(len,'\0'); if(len) ss.read(body.data(),len);

    auto r = ctrl_.handle(method, path, body);
    std::ostringstream res;
    if (r) {
        res<<"HTTP/1.1 "<<r->status<<(r->status==200?" OK":r->status==201?" Created":r->status==204?" No Content":"")<<"\r\n"
           <<"Content-Type: "<<r->type<<"\r\n"
           <<"Content-Length: "<<r->body.size()<<"\r\n\r\n"<<r->body;
    } else res<<"HTTP/1.1 404 Not Found\r\nContent-Length:0\r\n\r\n";
    auto s=res.str(); send(fd,s.data(),s.size(),0);
}

[[noreturn]] void aih::SimpleHttpServer::run() {
    int srv=socket(AF_INET,SOCK_STREAM,0),opt=1;
    setsockopt(srv,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
    sockaddr_in a{AF_INET,htons(port_),INADDR_ANY};
    bind(srv,(sockaddr*)&a,sizeof(a)); listen(srv,10);
    std::cout<<"HTTP on "<<port_<<"\n";
    while (true) {
        int c = accept(srv,nullptr,nullptr);
        handle(c);
        close(c);
    }
}