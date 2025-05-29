//
// Created by 125002 on 25. 5. 28.
//

#ifndef HTTPUSERCONTROLLER_HPP
#define HTTPUSERCONTROLLER_HPP

#include <optional>
#include <string>

#include "ports/in/IUserService.hpp"


namespace adapters::in::http
{
    struct HttpResponse {
        int status;
        std::string body;
        std::string type{"application/json"};
    };

    class HttpUserController {
    public:
        explicit HttpUserController(core::ports::in::IUserService&);
        std::optional<HttpResponse> handle(
            const std::string& method,
            const std::string& path,
            const std::string& body);
    private:
        core::ports::in::IUserService& service_;
    };
}

#endif //HTTPUSERCONTROLLER_HPP
