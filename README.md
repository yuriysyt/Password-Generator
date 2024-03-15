# Random Password Generator and Checker

This C++ program generates random passwords and checks their security based on predefined criteria. It can be used to create strong and secure passwords for various applications.

## Features
- Generates random passwords of variable length.
- Ensures passwords contain a mix of digits, uppercase letters, and lowercase letters.
- Checks generated passwords for security based on predefined criteria.
- Avoids patterns in generated passwords by shuffling characters.

## Requirements
- C++ compiler with support for C++11 or later.
- Standard C++ libraries.

## Usage
1. Compile the source code using a C++ compiler.
2. Run the compiled executable.
3. The program will generate and test multiple random passwords, displaying the results.

## How it Works
- The program uses a random number generator to create passwords of random length between 10 and 16 characters.
- Each password contains at least one digit, one uppercase letter, and one lowercase letter.
- The generated passwords are checked for security, ensuring they do not contain repeated characters or predictable patterns.
- Finally, the program displays the generated passwords and indicates whether they are secure.

## Contributing
Contributions are welcome! Feel free to open issues or submit pull requests to improve the code or add new features.