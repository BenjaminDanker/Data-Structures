#include <iostream>
#include <vector>
#include <numeric>
#include <stdexcept>
#include <stack>


bool isParenthesesBalanced(std::string paren) {
	std::stack<char> charStack;

	for (char x : paren) {
		if (x == '(' or x == '<') {
			charStack.push(x);
		}
		else {
			if (charStack.empty()) {
				return false;
			}
			else if (x == ')' and charStack.top() != '(' or x == '>' and charStack.top() != '<') {
				return false;
			}
			else {
				charStack.pop();
			}
		}
	}

	if (charStack.empty() == true) {
		return true;
	}
	else {
		return false;
	}
}

std::string decimalToHex(int number) {
	std::stack<char> hexStack;
	std::string hex;
	int remainder;

	while (number > 0) {
		remainder = number % 16;
		number /= 16;

		if (remainder <= 10) {
			hexStack.push(char(remainder));
		}
		else {
			if (remainder == 11) {
				hexStack.push('A');
			}
			else if (remainder == 12) {
				hexStack.push('B');
			}
			else if (remainder == 13) {
				hexStack.push('C');
			}
			else if (remainder == 14) {
				hexStack.push('D');
			}
			else if (remainder == 15) {
				hexStack.push('E');
			}
			else if (remainder == 16) {
				hexStack.push('F');
			}
		}
	}

	for (int i = 0; i < hexStack.size(); i++) {
		hex += hexStack.top();
		hexStack.pop();
	}

	return hex;
}

int main() {
	std::cout << isParenthesesBalanced("(<>)") << std::endl;

	std::cout << decimalToHex(15) << std::endl;
}