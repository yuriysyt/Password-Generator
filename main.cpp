#include "src/include/PasswordGenerator.h"
#include <iostream>
#include <ctime>

int main() {
    srand(time(0)); // Seed random number generator

    PasswordGenerator passwordGenerator;
    for (int i = 0; i < 321; i++) {
        std::string generatedPassword = passwordGenerator.generateRandomPassword();
        std::cout << "Generated Password: " << generatedPassword << std::endl;
        if (passwordGenerator.isSecurePassword(generatedPassword)) {
            std::cout << "Password is secure." << std::endl;
        } else {
            std::cout << "Password is not secure." << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
