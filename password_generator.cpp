#include <random>
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

// Function to generate a random password
string createRandomPassword() {
    random_device randomDevice; // Random device for seeding
    mt19937 randomNumberGenerator(randomDevice()); // Mersenne Twister pseudo-random number generator
    int passLength = (rand() % 7) + 10; // Rule 1: Generate a random length between 10 and 16 (inclusive)
    string characterSet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    string password; // Initialize password string

    // Rule 3: Ensure at least one digit, one uppercase letter, and one lowercase letter
    password += characterSet[rand() % 10];  // Digit
    password += characterSet[10 + rand() % 26];  // Uppercase letter
    password += characterSet[36 + rand() % 26];  // Lowercase letter

    // Rule 4: Generate the rest of the password
    for (int i = 0; i < passLength - 3; i++) {
        // Ensure no repeated characters
        while (true) {
            char nextChar = characterSet[rand() % 62];
            if (password.find(nextChar) == string::npos) {
                password += nextChar;
                break;
            }
        }
    }

    // Rule 5: Shuffle the password to avoid patterns
    shuffle(password.begin(), password.end(), randomNumberGenerator);
    
    return password; // Return the generated password
}

// Function to check if a password is secure
bool isSecurePassword(const string& password) {
    // Check if password length is between 10 and 16
    if (password.length() > 16 || password.length() < 10) {
        return false;
    }

    // Three consecutive characters are identical
    for (int i = 2; i < password.length(); ++i) {
        char currentChar = password[i];
        if (currentChar == password[i - 1] && currentChar == password[i - 2]) {
            return false;
        }
    }

    int digitCount = 0; 
    int upperCount = 0; 
    int lowerCount = 0; 

    // Check for at least one digit, uppercase, and lowercase letter
    for (char currentChar : password) {
        if (isdigit(currentChar)) {
            digitCount++;
        } else if (isupper(currentChar)) {
            upperCount++;
        } else if (islower(currentChar)) {
            lowerCount++;
        }
    }

    // Ensure at least one digit, one uppercase letter, and one lowercase letter
    return digitCount > 0 && upperCount > 0 && lowerCount > 0;
}

int main() {
    srand(time(0)); // Seed random number generator

    // Generate and test 321 passwords
    for (int i = 0; i < 321; i++) {
        string generatedPassword = createRandomPassword();
        cout << "Generated Password: " << generatedPassword << endl; // Output password
        if (isSecurePassword(generatedPassword)) {
            cout << "Password is secure." << endl;
        } else {
            cout << "Password is not secure." << endl;
        }
        cout << endl;
    }

    return 0;
}
