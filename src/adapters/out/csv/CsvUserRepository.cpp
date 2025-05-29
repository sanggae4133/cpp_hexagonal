//
// Created by 125002 on 25. 5. 28.
//

#include "CsvUserRepository.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>

using core::domain::model::User;
namespace fs = std::filesystem;
namespace csv = adapters::out::csv;

csv::CsvUserRepository::CsvUserRepository(fs::path dir) {
    file_ = dir / "users.csv";
    fs::create_directories(dir);
    if (!fs::exists(file_)) { std::ofstream(file_) << "id,name,age\n"; }
    reload();
}

void csv::CsvUserRepository::reload() {
    cache_.clear();
    std::ifstream in(file_);
    std::string line; std::getline(in, line);
    while (std::getline(in, line)) {
        std::stringstream ss(line); std::string cell;
        std::vector<std::string> c;
        while (std::getline(ss, cell, ',')) c.push_back(cell);
        if (c.size() == 3) {
            cache_.push_back({ std::stoull(c[0]), c[1], std::stoi(c[2]) });
        }
    }
}

void csv::CsvUserRepository::persist() {
    std::ofstream out(file_); out << "id,name,age\n";
    for (auto& u: cache_)
        out << u.id << ',' << u.name << ',' << u.age << '\n';
}

void csv::CsvUserRepository::save(const User& u) {
    cache_.push_back(u);
    std::ofstream(file_, std::ios::app) << u.id << ',' << u.name << ',' << u.age << '\n';
}

std::optional<User> csv::CsvUserRepository::findById(std::uint64_t id) {
    auto it = std::find_if(cache_.begin(), cache_.end(),
                           [id](const User& u) { return u.id == id; });
    if (it != cache_.end()) return *it;
    return std::nullopt;
}

std::vector<User> csv::CsvUserRepository::findAll() {
    return cache_;
}

bool csv::CsvUserRepository::remove(std::uint64_t id) {
    cache_.erase(
        std::remove_if(
            cache_.begin(),
            cache_.end(),
            [id](auto& u) {
                return u.id == id;
    }),
    cache_.end()
    );
    persist();
    return true;
}

