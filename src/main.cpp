#include <string>
#include <iostream>
#include "../include/scanner.h"
#include "../include/parser.h"

int main() {
    std::string inputString;
    std::string buffer;
    while (true) {
        inputString.clear();
        std::cout << "?- ";
        while (std::getline(std::cin, buffer)) {
            while (buffer.back() == ' ') {
                buffer.pop_back();
            }
            inputString += buffer;
            if (inputString.empty()) break;

            if (buffer.back() == '.') {
                break;
            }
            std::cout << "| ";
        }
        if (inputString.empty()) continue;

        if (inputString == "halt.") {
            break;
        }

        try {
            Scanner scanner(inputString);
            Parser parser(scanner);
            parser.buildExpression();
            std::cout << parser.getResult() << std::endl;
        } catch (std::string& msg) {
            std::cout << "\033[1;31m" << msg << "\033[0m" << std::endl;
        } catch (...) {
            std::cout << "\033[1;31munexpected exception\033[0m" << std::endl;
        }
    }
    return 0;
}