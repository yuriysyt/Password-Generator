#ifndef PASSWORD_GENERATOR_H
#define PASSWORD_GENERATOR_H

#include <string>

class PasswordGenerator {
public:
    PasswordGenerator();
    std::string generateRandomPassword();
    bool isSecurePassword(const std::string& password) const;

private:
    std::string characterSet;
};

#endif // PASSWORD_GENERATOR_H
