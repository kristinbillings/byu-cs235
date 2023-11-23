#include <iostream>
#include <string>

using namespace std;

std::string input(std::string prompt) {
    std::cout << prompt;
    std::cout.flush();
    std::string response;
    std::getline(std::cin, response);
    return response;
}

int main(int argc, char const* argv[]) {
    string operation;

    while (true) {
        operation = input("operation: ");

        if (operation.empty()) {
            break;
        }
        while (operation != "add" and operation != "subtract" and operation != "multiply" and
               operation != "divide" and operation != "mod") {
            std::cout << operation << " isn't a valid operation" << std::endl;
            operation = input("operation: ");
            if (operation.empty()) {
                return 0;
            }
        }

        string lOperand1;
        string rOperand1;
        std::cout << "left operand: ";
        std::getline(cin, lOperand1);
        std::cout << "right operand: ";
        std::getline(cin, rOperand1);

        int lOperand = std::stoi(lOperand1);
        int rOperand = std::stoi(rOperand1);

        int finalAnswer;

        if (operation == "add") {
            finalAnswer = lOperand + rOperand;
        } else if (operation == "subtract") {
            finalAnswer = lOperand - rOperand;
        } else if (operation == "multiply") {
            finalAnswer = lOperand * rOperand;
        } else if (operation == "divide") {
            finalAnswer = lOperand / rOperand;
        } else if (operation == "mod") {
            finalAnswer = lOperand % rOperand;
        }

        std::cout << finalAnswer << std::endl;

    }
return 0;
}