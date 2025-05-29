//
// Created by 125002 on 25. 5. 28.
//

#include "UserServiceImpl.hpp"
#include <chrono>
#include <stdexcept>

using core::domain::model::User;
namespace cu = core::usecase;

cu::UserServiceImpl::UserServiceImpl(core::ports::out::IUserRepository & r) : repo_{r} {}

std::uint64_t cu::UserServiceImpl::generateId() {
    return static_cast<std::uint64_t>(
        std::chrono::high_resolution_clock::now().time_since_epoch().count());
}

std::uint64_t cu::UserServiceImpl::createUser(const std::string& name, int age) {
    if (name.empty() || age < 0) throw std::invalid_argument("Invalid data");
    std::uint64_t id = generateId();
    repo_.save(User{id, name, age});
    return id;
}

std::vector<User> cu::UserServiceImpl::readUsers() { return repo_.findAll(); }

bool cu::UserServiceImpl::deleteUser(std::uint64_t id) {
    if (!repo_.findById(id)) return false;
    repo_.remove(id);
    return true;
}
