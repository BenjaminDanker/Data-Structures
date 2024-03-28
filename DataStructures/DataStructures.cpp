#include <iostream>
#include <vector>
#include <numeric>
#include <stdexcept>
#include <stack>


bool isOperand(char x) {
    return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

std::string getInfix(std::string postfix) {
    std::stack<std::string> stck;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isOperand(postfix[i])) {
            std::string op(1, postfix[i]);
            stck.push(op);
        }
        else {
            std::string op1 = stck.top();
            stck.pop();
            std::string op2 = stck.top();
            stck.pop();
            stck.push("(" + op2 + postfix[i] + op1 + ")");
        }
    }

    return stck.top();
}

int main() {
    std::string postfix = "AB+CDE/*-F+";
    std::cout << getInfix(postfix);

    return 0;
}