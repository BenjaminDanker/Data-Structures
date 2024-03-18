#include <iostream>
#include <vector>
#include <numeric>
#include <stdexcept>
#include <stack>

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

std::string infixToPostfix(const std::string& infix) {
    std::stack<char> operatorsStack;
    std::string postfix;

    for (auto x : infix) {
        if (x == ' ') {
            continue;
        }
        if (isalnum(x)) {
            postfix += x;
        }
        else if (x == '(') {
            operatorsStack.push(x);
        }
        else if (x == ')') {
            while (operatorsStack.top() != '(') {
                postfix += operatorsStack.top();
                operatorsStack.pop();
            }
            operatorsStack.pop();
        }
        else {
            while (!operatorsStack.empty() and precedence(x) <= precedence(operatorsStack.top())) {
                postfix += operatorsStack.top();
                operatorsStack.pop();
            }
            operatorsStack.push(x);
        }
    }
    while (!operatorsStack.empty()) {
        postfix += operatorsStack.top();
        operatorsStack.pop();
    }

    return postfix;
}

int main() {
    //std::string infixExpression = "((A + B) - C * (D/E)) + F";
    std::string infixExpression = "A + B * C + D";
    std::string postfixExpression = infixToPostfix(infixExpression);

    std::cout << "Infix Expression: " << infixExpression << std::endl;
    std::cout << "Postfix Expression: " << postfixExpression << std::endl;
}