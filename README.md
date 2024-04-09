# Random Password Generator and Checker

Welcome to the Random Password Generator and Checker project! This C++ program is designed to generate strong and secure passwords while also verifying their security based on predefined criteria.

## Features

- **Password Generation**: Generate random passwords of variable length.
- **Security Checking**: Ensure passwords contain a mix of digits, uppercase letters, and lowercase letters.
- **Security Verification**: Check generated passwords for security, avoiding patterns to enhance security.
- **User-friendly Interface**: Easy-to-use interface displaying generated passwords and their security status.

## Requirements

- C++ compiler with support for C++14 or later.
- Standard C++ libraries.

## Usage

1. **Compilation**:
   You can compile the source code using a C++ compiler. You have two options:

   - Using `g++` directly:
     ```
     g++ -std=c++14 -o main main.cpp src/PasswordGenerator.cpp
     ```

   - Using `make`:
     ```
     make
     ```

2. **Execution**:
   Run the compiled executable:
   ```
   ./main
   ```

3. **Result**:
   The program will generate and test multiple random passwords, displaying the results.

## How it Works

- The program utilizes a random number generator to create passwords of random length between 10 and 16 characters.
- Each generated password contains at least one digit, one uppercase letter, and one lowercase letter to ensure security.
- Passwords are checked for security, ensuring they do not contain repeated characters or predictable patterns.
- Finally, the program displays the generated passwords and indicates whether they are secure.

## Contributing

Contributions to this project are welcome! Whether you want to improve the code, add new features, or suggest enhancements, feel free to open issues or submit pull requests.