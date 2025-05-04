#include <iostream>
#include <cctype>
#include <string>
#include "lab6c.h"
using namespace std;

class Expression {
public:
    string infix, postfix;
    void getInfix();
    void infixToPostfix();
    int evaluatePostfix();
};

void Expression::getInfix() {
    cout << "Enter infix expression: ";
    cin >> infix;
}

int precedence(char op) {
    return (op == '+' || op == '-') ? 1 : (op == '*' || op == '/') ? 2 : 0;
}

void Expression::infixToPostfix() {
    Stack s;
    postfix = "";

    for (char ch : infix) {
        if (isalnum(ch)) 
            postfix += ch;
        else if (ch == '(') 
            s.push(ch);
        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(')
                postfix += s.pop();
            s.pop();
        } else {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch))
                postfix += s.pop();
            s.push(ch);
        }
    }

    while (!s.isEmpty()) postfix += s.pop();
    cout << "Postfix Expression: " << postfix << endl;
}

int Expression::evaluatePostfix() {
    Stack s;
    for (char ch : postfix) {
        if (isdigit(ch))
            s.push(ch - '0');
        else {
            int b = s.pop(), a = s.pop();
            s.push((ch == '+') ? a + b : (ch == '-') ? a - b : (ch == '*') ? a * b : a / b);
        }
    }
    return s.pop();
}

int main() {
    Expression exp;
    int choice;

    while (true) {
        cout << "\n1. Get Infix\n2. Infix to Postfix\n3. Evaluate Postfix\n4. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1: exp.getInfix(); break;
            case 2: exp.infixToPostfix(); break;
            case 3: cout << "Result: " << exp.evaluatePostfix() << endl; break;
            case 4: return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }
}
