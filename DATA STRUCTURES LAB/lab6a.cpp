//Stack ADT-Array Implementation
#include<iostream>
using namespace std;

#define SIZE 5

class stack{
    private:
        char arr[SIZE];
        int top;

    public:
        stack() : top(-1){}

        void push(char value);
        void pop();
        void peek();
        int getmenu(int choice);

};

int main()
{
    stack s;
    int choice;
    char value;
    while (true) {
        choice = s.getmenu(choice);

        switch(choice){
            case 1:
                cout << "Enter the value to be inserted :\n";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.peek();
                break;        

            case 4:
                exit(0);

            default:
                cout << " Invalid choice.Please try again.\n";
    }
    }
    return 0;
}

//Function for the menu
int stack::getmenu(int choice){
    cout<<" -----MENU----- \n";
    cout<<"1.Push\n";
    cout<<"2.Pop\n";
    cout<<"3.Peek\n";
    cout<<"4.Exit\n";
    cout<<"Enter your choice:\n";
    cin>>choice;
    return choice;
}

//Function for push
void stack::push(char value){
    if(top == SIZE -1){
        cout << "Stack Overflow! The value cannot be pushed into the stack.\n";
    }
    else{
        arr[++top] = value;
        cout << " The value ' " << value << " ' is pushed into the stack\n" << endl;
    }
}

//Function for pop
void stack::pop(){
    if(top == -1){
        cout << "Stack Underflow! The Stack is empty.\n";
    }
    else{
        cout << " The value ' " << arr[top] << " ' is popped into the stack\n" << endl;
        top--;
    }
}

//Function for peek
void stack::peek(){
    if(top == -1){
        cout << "Stack Underflow! The Stack is empty.\n";
    }
    else{
        cout << " The value ' " << arr[top] << " ' is in the top of the stack\n" << endl;
    }
}
