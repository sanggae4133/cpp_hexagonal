#include <iostream>

#include "wiring/CliAppFactory.hpp"
#include "wiring/HttpAppFactory.hpp"

int main_cli();
int main_http();

int main() {
    int choice;

    std::cout << "Choose an option(1: cli, 2: http):\n";
    std::cin >> choice;

    if (choice == 1) {
        // Run CLI application
        return main_cli();
    } else if (choice == 2) {
        // Run HTTP application
        return main_http();
    } else {
        std::cout << "Invalid choice. Exiting.\n";
    }

    return 0;
}

int main_cli() {
    auto app = infra::wiring::makeCliApp();
    app.controller.run();

    return 0;  // exit code
}

int main_http() {
    auto app = infra::wiring::makeHttpApp(8080);
    app.server.run();   // blocking

    return 0;  // never reached
}