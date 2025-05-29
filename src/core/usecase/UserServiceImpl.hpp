//
// Created by 125002 on 25. 5. 28.
//

#ifndef USERSERVICEIMPL_HPP
#define USERSERVICEIMPL_HPP

#include "../ports/in/IUserService.hpp"
#include "../ports/out/IUserRepository.hpp"

namespace core::usecase {
    class UserServiceImpl final : public core::ports::in::IUserService {
    public:
        explicit UserServiceImpl(core::ports::out::IUserRepository&);
        std::uint64_t createUser(const std::string&, int) override;
        std::vector<core::domain::model::User> readUsers() override;
        bool deleteUser(std::uint64_t id) override;
    private:
        core::ports::out::IUserRepository& repo_;
        static std::uint64_t generateId();
    };
}

#endif //USERSERVICEIMPL_HPP
