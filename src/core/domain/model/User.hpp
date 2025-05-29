//
// Created by 125002 on 25. 5. 28.
//

#ifndef USER_HPP
#define USER_HPP

#include <cstdint>
#include <string>

namespace core::domain::model {
    struct User {
        std::uint64_t id{};
        std::string name;
        int age{};
    };
}

#endif //USER_HPP
