//
// Created by 125002 on 25. 5. 28.
//

#ifndef IUSERSERVICE_HPP
#define IUSERSERVICE_HPP

#include <vector>
#include "../../domain/model/User.hpp"

namespace core::ports::in {
    using core::domain::model::User;

    struct IUserService {
        virtual ~IUserService() = default;

        virtual std::uint64_t createUser(const std::string& name, int age) = 0;
        virtual std::vector<User> readUsers() = 0;
        virtual bool deleteUser(std::uint64_t id) = 0;
    };
}

#endif //IUSERSERVICE_HPP
