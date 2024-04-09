#include "include/PasswordGenerator.h"
#include <random>
#include <algorithm>

PasswordGenerator::PasswordGenerator() {
    characterSet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
}

std::string PasswordGenerator::generateRandomPassword() {
    std::random_device randomDevice;
    std::mt19937 randomNumberGenerator(randomDevice());
    int passLength = (randomNumberGenerator() % 7) + 10;
    std::string password;
    password += characterSet[randomNumberGenerator() % 10]; // Digit
    password += characterSet[10 + randomNumberGenerator() % 26]; // Uppercase letter
    password += characterSet[36 + randomNumberGenerator() % 26]; // Lowercase letter

    for (int i = 0; i < passLength - 3; i++) {
        while (true) {
            char nextChar = characterSet[randomNumberGenerator() % 62];
            if (password.find(nextChar) == std::string::npos) {
                password += nextChar;
                break;
            }
        }
    }

    std::shuffle(password.begin(), password.end(), randomNumberGenerator);
    return password;
}

bool PasswordGenerator::isSecurePassword(const std::string& password) const {
    if (password.length() > 16 || password.length() < 10) {
        return false;
    }

    for (int i = 2; i < password.length(); ++i) {
        char currentChar = password[i];
        if (currentChar == password[i - 1] && currentChar == password[i - 2]) {
            return false;
        }
    }

    int digitCount = 0;
    int upperCount = 0;
    int lowerCount = 0;

    for (char currentChar : password) {
        if (isdigit(currentChar)) {
            digitCount++;
        } else if (isupper(currentChar)) {
            upperCount++;
        } else if (islower(currentChar)) {
            lowerCount++;
        }
    }

    return digitCount > 0 && upperCount > 0 && lowerCount > 0;
}
