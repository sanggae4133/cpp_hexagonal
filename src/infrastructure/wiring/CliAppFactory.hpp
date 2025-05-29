//
// Created by 125002 on 25. 5. 28.
//

#ifndef CLIAPPFACTORY_HPP
#define CLIAPPFACTORY_HPP

#include "in/cli/controller/CliUserController.hpp"
#include "out/csv/CsvUserRepository.hpp"

#include "usecase/UserServiceImpl.hpp"

namespace infra::wiring
{
    struct CliApp
    {
        adapters::out::csv::CsvUserRepository repo{"../../data"};
        core::usecase::UserServiceImpl        service{repo};
        adapters::in::cli::CliUserController  controller{service};
    };
    inline CliApp makeCliApp(){ return {}; }
}

#endif //CLIAPPFACTORY_HPP
