//
// Created by 125002 on 25. 5. 29.
//

#ifndef SIMPLEHTTPSERVER_HPP
#define SIMPLEHTTPSERVER_HPP

#include "../controller/HttpUserController.hpp"

namespace adapters::in::http {
    class SimpleHttpServer {
    public:
        SimpleHttpServer(int port, core::ports::in::IUserService&);
        [[noreturn]] void run();
    private:
        int port_;
        HttpUserController ctrl_;
        void handle(int sock);
    };
}

#endif //SIMPLEHTTPSERVER_HPP
