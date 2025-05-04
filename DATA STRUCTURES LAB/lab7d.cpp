//STRING - Stack ADT-Array Implementation
#include<iostream>
using namespace std;

#define SIZE 100

class stack{
    private:
        char arr[SIZE];
        int top;

    public:
        stack() : top(-1){}

        void push(char value);
        void pop();
        void result(string input);
};

int main()
{
    stack s;
    string input;
    cout << " Enter the string: ";
    getline(cin,input);
    s.result(input);
    return 0;
}

//Function for push
void stack::push(char value){
    if(top == SIZE -1){
        cout << "Stack Overflow! The value cannot be pushed into the stack.\n";
    }
    else{
        arr[++top] = value;
    }
}

//Function for pop
void stack::pop(){
    if(top == -1){
        cout << "Stack Underflow! The Stack is empty.\n";
    }
    else{
        top--;
    }
}

//Function to process the given string
void stack::result(string input){
   for (char ch : input){
    if(ch == '+'){
        pop();   
    }
    else{
        push(ch);
    }
   }
   cout << " OUTPUT: ";
   for(int i = 0;i <= top; i++){
     cout<< arr[i];
   }
   cout << endl;
}