//
// Created by 125002 on 25. 5. 28.
//

#ifndef HTTPAPPFACTORY_HPP
#define HTTPAPPFACTORY_HPP

#include "in/http/server/SimpleHttpServer.hpp"
#include "out/csv/CsvUserRepository.hpp"

#include "usecase/UserServiceImpl.hpp"

namespace infra::wiring
{
    struct HttpApp
    {
        adapters::out::csv::CsvUserRepository repo;
        core::usecase::UserServiceImpl        service;
        adapters::in::http::SimpleHttpServer  server;

        // **inline** 구현 → 오브젝트 파일 필요 없음
        explicit HttpApp(int port)
        : repo{"../../data"}, service{repo}, server{port, service} {}
    };

    inline HttpApp makeHttpApp(int port = 8080) { return HttpApp{port}; }
}

#endif //HTTPAPPFACTORY_HPP
