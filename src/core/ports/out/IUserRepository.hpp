//
// Created by 125002 on 25. 5. 28.
//

#ifndef IUSERREPOSITORY_HPP
#define IUSERREPOSITORY_HPP

#include <optional>
#include <vector>
#include "../../domain/model/User.hpp"

namespace core::ports::out {
    using core::domain::model::User;

    struct IUserRepository {
        virtual ~IUserRepository() = default;

        virtual void save(const User&) = 0;
        virtual std::optional<User> findById(std::uint64_t) = 0;
        virtual std::vector<User> findAll() = 0;
        virtual bool remove(std::uint64_t id) = 0;
    };
}

#endif //IUSERREPOSITORY_HPP
