#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node(char val) : data(val), next(nullptr) {}
};

class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}
    ~Stack();
    void push(char val);
    char pop();
    char peek();
    bool isEmpty();
};

Stack::~Stack() {
    while (!isEmpty()) pop();
}

void Stack::push(char val) {
    Node* newNode = new Node(val);
    newNode->next = top;
    top = newNode;
}

char Stack::pop() {
    if (isEmpty()) return '\0';
    char val = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return val;
}

char Stack::peek() { return (isEmpty()) ? '\0' : top->data; }

bool Stack::isEmpty() { return top == nullptr; }

#endif
