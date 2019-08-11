#include <iostream>
#include <vector>
#include <cassert>
#include <map>

using namespace std;

int evaluatePostfix(const char* str);
int evaluationInfix(const char* str);

int main() {
    std::cout << "Hello, World!" << std::endl;

    // postfix evaluation
    assert(evaluatePostfix("19+") == 10);
    assert(evaluatePostfix("19+28+*") == 100);
    assert(evaluatePostfix("12+23+*5/") == 3);

    // infix evaluation
    assert(evaluationInfix("1+9") == 10);
    assert(evaluationInfix("(1+9)*(2+8)") == 100);
    assert(evaluationInfix("(1+2)*(2+3)/5") == 3);

    return 0;
}

int eval(char ch, int lhs, int rhs) {
    switch (ch) {
        case '+': return lhs + rhs;
        case '-': return lhs - rhs;
        case '/': return lhs / rhs;
        case '*': return lhs * rhs;
        default:
            throw invalid_argument("invalid char");
    }
}

int evaluatePostfix(const char* str) {
    vector<int> stack;
    string strVal(str);

    for (char ch: strVal) {
        if (isdigit(ch)) {
            stack.push_back(ch - '0');
        } else {
            int rhs = stack.back();
            stack.pop_back();
            int lhs = stack.back();
            stack.pop_back();
            stack.push_back(eval(ch, lhs, rhs));
        }
    }
    cout << stack.back() << "\n";
    return stack.back();
}

int evaluationInfix(const char* str) {
    vector<int> value;
    vector<char> oper;
    map<char, int> priority;
    priority['+'] = 1;
    priority['-'] = 1;
    priority['*'] = 2;
    priority['/'] = 2;

    string strVal(str);
    for (auto ch: strVal) {
        if (isdigit(ch)) {
            value.push_back(ch - '0');
        } else {
            if (ch == '(') {
                oper.push_back(ch);
            } else if (ch == ')') {
                char op = oper.back(); oper.pop_back();
                int rhs = value.back(); value.pop_back();
                int lhs = value.back(); value.pop_back();
                value.push_back(eval(op, lhs, rhs));
                oper.pop_back();    // (까지 제거.
            } else {
                if (!oper.empty() && priority[ch] <= priority[oper.back()]) {
                    char op = oper.back(); oper.pop_back();
                    int rhs = value.back(); value.pop_back();
                    int lhs = value.back(); value.pop_back();
                    value.push_back(eval(op, lhs, rhs));
                }
                oper.push_back(ch);
            }
        }
    }
    while (!oper.empty()) {
        char op = oper.back(); oper.pop_back();
        int rhs = value.back(); value.pop_back();
        int lhs = value.back(); value.pop_back();
        value.push_back(eval(op, lhs, rhs));
    }
    cout << "= " << value.back() << "\n";
    return value.back();
}