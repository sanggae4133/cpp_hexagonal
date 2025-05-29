//
// Created by 125002 on 25. 5. 28.
//

#ifndef CLIUSERCONTROLLER_HPP
#define CLIUSERCONTROLLER_HPP

#include "ports/in/IUserService.hpp"

namespace adapters::in::cli {
    class CliUserController {
    public:
        explicit CliUserController(core::ports::in::IUserService&);
        void run();
    private:
        core::ports::in::IUserService& service_;
        void showMenu() const;
        void handleCreate();
        void handleList();
        void handleDelete();
    };
}

#endif //CLIUSERCONTROLLER_HPP
