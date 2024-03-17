#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

int evaluatePostfix(const string& expression) {
    stack<int> operands;

    for (char ch : expression) {
        if (isdigit(ch)) {
            operands.push(ch - '0');
        } else if (ch == ' ') {
            continue; 
        } else {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            switch (ch) {
                case '+':
                    operands.push(operand1 + operand2);
                    break;
                case '-':
                    operands.push(operand1 - operand2);
                    break;
                case '*':
                    operands.push(operand1 * operand2);
                    break;
                case '/':
                    operands.push(operand1 / operand2);
                    break;
                default:
                   cout << "Invalid character in expression: " << ch << endl;
                    return -1;
            }
        }
    }

    return operands.top();
}

int main() {
    string expression;
    // cout << "Enter a postfix expression: ";
    // getline(cin, expression);
    expression = "66+";

    int result = evaluatePostfix(expression);
    cout << "Result: " << result << endl;

    return 0;
}
