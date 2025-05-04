//Valid Parenthesis
#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Parenthesis{
    public:
        int getmenu();
        bool check(string expr);      
};

int main()
{
    Parenthesis p;
    int choice;
    string expr;
    while (true) {
        choice = p.getmenu();

        switch(choice){
            case 1:
                cout << "Enter a string of parentheses: ";
                cin >> expr;
                if (p.check(expr)) {
                    cout << "The parentheses are balanced.\n";
                } else {
                    cout << "The parentheses are not balanced.\n";
                }
                break;       

            case 2:
                exit(0);

            default:
                cout << " Invalid choice.Please try again.\n";
        }
    }
    return 0;
}

//Function for the menu
int Parenthesis::getmenu(){
    int choice;
    cout<<" -----MENU----- \n";
    cout<<"1.Check balance\n";
    cout<<"2.Exit\n";
    cout<<"Enter your choice:\n";
    cin>>choice;
    return choice;
}

//Function for checking the valid parenthesis
bool Parenthesis::check(string expr){
    stack<char> s;
    for (char ch : expr){
        if(ch == '(' ){
            s.push(ch);
        }
        else if(ch == ')'){
            if(s.empty() || s.top() != '('){
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

