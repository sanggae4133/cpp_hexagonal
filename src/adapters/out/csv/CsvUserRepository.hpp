//
// Created by 125002 on 25. 5. 28.
//

#ifndef CSVUSERREPOSITORY_HPP
#define CSVUSERREPOSITORY_HPP

#include <filesystem>
#include <vector>

#include "ports/out/IUserRepository.hpp"

namespace adapters::out::csv {
    class CsvUserRepository : public core::ports::out::IUserRepository {
    public:
        explicit CsvUserRepository(std::filesystem::path dataDir);
        void save(const core::domain::model::User&) override;
        std::optional<core::domain::model::User> findById(std::uint64_t) override;
        std::vector<core::domain::model::User> findAll() override;
        bool remove(std::uint64_t id) override;
    private:
        std::filesystem::path file_;
        std::vector<core::domain::model::User> cache_;
        void reload();
        void persist();
    };
}

#endif //CSVUSERREPOSITORY_HPP
