#include <iostream>
#include <vector>
#include <cassert>
#include <map>

using namespace std;

string translateReversePolishNotation(const string& input);
string translateReversePolishNotation2(const string& input);
string translateReversePolishNotationWithParen(const string& input);

int main() {
    // a+b => ab+
    // a*b => ab*
    // a+b*c => abc*+
    // a*b+c => ab*c+
    // a+b*c-d => abc*d-+
    // a+b-c*d/e => ab+cd*e/-

    assert(translateReversePolishNotation("a+b") == "ab+");
    assert(translateReversePolishNotation("a*b") == "ab*");
    assert(translateReversePolishNotation("a+b*c") == "abc*+");
    assert(translateReversePolishNotation("a*b+c") == "ab*c+");
    // 오류 발견.
    assert(translateReversePolishNotation("a+b*c-d") == "abc*+d-");
    assert(translateReversePolishNotation("a+b-c*d/e") == "ab+cd*e/-");

    // 우선순위 활용.
    assert(translateReversePolishNotation2("a+b") == "ab+");
    assert(translateReversePolishNotation2("a*b") == "ab*");
    assert(translateReversePolishNotation2("a+b*c") == "abc*+");
    assert(translateReversePolishNotation2("a*b+c") == "ab*c+");
    assert(translateReversePolishNotation2("a+b*c-d") == "abc*+d-");
    assert(translateReversePolishNotation2("a+b-c*d/e") == "ab+cd*e/-");

    // 괄호 처리.
    assert(translateReversePolishNotationWithParen("(a+b)*c") == "ab+c*");
    assert(translateReversePolishNotationWithParen("(a+b)*(c-d)") == "ab+cd-*");
    assert(translateReversePolishNotationWithParen("(a+b)*c+d") == "ab+c*d+");
    assert(translateReversePolishNotationWithParen("((a+b)*c)+d") == "ab+c*d+");
    assert(translateReversePolishNotationWithParen("((a+b)+c)*d") == "ab+c+d*");

    return 0;
}

// a, + -> a b, + -> * => a b, + * -> c -> a b c, + * -> a b c * +
//
// a + b - c => a, + => a b, + => a b +, - => a b + c, - => a b + c -
// a + b * c => a, + => a b, + => a b, + * => a b c, + * => a b c * +
// a * b + c => a, * => a b, * => a b *, + => a b * c, +
// a * b * c + d => a, * => a b, * => a b *, * => a b * c, * => a b *  c *, + => a b * c * d +
//

// 우선순위를 공식화하지 못하고 작성함. -- 오류 발견.
string translateReversePolishNotation(const string& input) {
    vector<char> stack1;
    vector<char> op_stack;
    op_stack.push_back('E');

    for (char ch: input) {
        switch(ch) {
            case '+':
            case '-': {
                // 들어 있는 operator를 다 뻬야 함. left associative 때문에.
                while (op_stack.back() != 'E') {
                    stack1.push_back(op_stack.back());
                    op_stack.pop_back();
                }
                op_stack.push_back(ch);
                break;
            }
            case '/':
            case '*': {
                if (op_stack.back() == '*' || op_stack.back() == '/') {
                    stack1.push_back(op_stack.back());
                    op_stack.pop_back();
                }
                op_stack.push_back(ch);
                break;
            }
            default: {    // digit
                stack1.push_back(ch);
            }
        }
    }
    string output;
    for (char ch: stack1) {
        output += ch;
    }
    while (op_stack.back() != 'E') {
        output += op_stack.back();
        op_stack.pop_back();
    }
    cout << output << "\n";
    return output;
}

string translateReversePolishNotation2(const string& input) {
    vector<char> stack1;
    stack1.push_back('E');
    vector<char> op_stack;
    op_stack.push_back('E');

    map<char, int> priority;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        priority[ch] = 3;
    }
    priority['+'] = 1;
    priority['-'] = 1;
    priority['*'] = 2;
    priority['/'] = 2;
    priority['E'] = 0;

    for (char ch: input) {
        while (priority[ch] <= priority[op_stack.back()]) {
            stack1.push_back(op_stack.back());
            op_stack.pop_back();
        }
        // operand도 op_stack에 넣었다가 우선순위를 비교해서 stack1으로 옮긴다.
        op_stack.push_back(ch);
    }
    string output;
    for (char ch: stack1) {
        if (ch != 'E')
            output += ch;
    }
    while (op_stack.back() != 'E') {
        output += op_stack.back();
        op_stack.pop_back();
    }
    cout << output << "\n";
    return output;
}

string translateReversePolishNotationWithParen(const string& input) {
    vector<char> stack1;
    stack1.push_back('E');
    vector<char> op_stack;
    op_stack.push_back('E');

    map<char, int> priority;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        priority[ch] = 3;
    }
    priority['+'] = 1;
    priority['-'] = 1;
    priority['*'] = 2;
    priority['/'] = 2;
    priority['('] = 0;
    priority['E'] = -1;

    for (char ch: input) {
        if (ch == ')') {
            while (op_stack.back() != '(') {
                stack1.push_back(op_stack.back());
                op_stack.pop_back();
            }
            // '(' 제거.
            op_stack.pop_back();
        } else {
            if (ch != '(') {
                while (priority[ch] <= priority[op_stack.back()]) {
                    stack1.push_back(op_stack.back());
                    op_stack.pop_back();
                }
            }
            // operand도 op_stack에 넣었다가 우선순위를 비교해서 stack1으로 옮긴다.
            op_stack.push_back(ch);
        }
    }
    string output;
    for (char ch: stack1) {
        if (ch != 'E')
            output += ch;
    }
    while (op_stack.back() != 'E') {
        output += op_stack.back();
        op_stack.pop_back();
    }
    cout << output << "\n";
    return output;
}