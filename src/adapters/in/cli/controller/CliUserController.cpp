//
// Created by 125002 on 25. 5. 28.
//

#include "CliUserController.hpp"
#include <iostream>

using core::domain::model::User;
namespace aic = adapters::in::cli;

aic::CliUserController::CliUserController(core::ports::in::IUserService& s) : service_{s} {}

void aic::CliUserController::showMenu() const {
    std::cout << "\n1) Create User\n"
              << "2) List Users\n"
              << "3) Delete User\n"
              << "4) Exit\n"
              << "Choose an option: ";
}

void aic::CliUserController::handleCreate() {
    std::string name; int age;
    std::cout << "Name : "; std::getline(std::cin, name);
    std::cout << "Age : "; std::cin >> age; std::cin.ignore();
    auto id = service_.createUser(name, age);
    std::cout << "Create id = " << id << "\n";
}

void aic::CliUserController::handleList()
{
    for (auto& u : service_.readUsers())
        std::cout << u.id << " | " << u.name << " | " << u.age << '\n';
}

void aic::CliUserController::handleDelete()
{
    std::uint64_t id;
    std::cout << "Id : "; std::cin >> id; std::cin.ignore();
    std::cout << (service_.deleteUser(id) ? "Deleted\n" : "Not found\n");
}

void aic::CliUserController::run()
{
    int m;
    while (true)
    {
        showMenu(); std::cin >> m; std::cin.ignore();
        if (m == 0) break;
        if (m == 1) handleCreate();
        else if (m == 2) handleList();
        else if (m == 3) handleDelete();
        else break;
    }
}