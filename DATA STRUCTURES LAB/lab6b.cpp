//Stack ADT-Singly linked list
#include<iostream>
using namespace std;

class stack{
    private:
        struct node{
            char data;
            struct node* next; 
       }*top;

    public:
        stack(){
            top = nullptr;
        }

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
      struct node* newnode = (struct node*)malloc(sizeof(struct node));
      newnode->data = value;
      newnode->next = top;
      top = newnode;
      cout << " The value ' " << value << " ' is pushed into the stack\n" << endl;
}

//Function for pop
void stack::pop(){
    if(top == nullptr){
        cout << "Stack Underflow! The Stack is empty.\n";
    }
    else{
        node* temp = top;
        cout << " The value ' " << top->data << " ' is popped into the stack\n" << endl;
        top = top->next;
        delete temp;
    }
}

//Function for peek
void stack::peek(){
    if(top == nullptr){
        cout << "Stack Underflow! The Stack is empty.\n";
    }
    else{
        cout << " The value ' " << top->data << " ' is in the top of the stack\n" << endl;
    }
}
