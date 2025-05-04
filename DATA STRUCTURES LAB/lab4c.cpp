//List ADT-Singly linked list 
#include<iostream>
#include"lab4b.h"
using namespace std;

int main()
{
    Sll list1,list2,list3;
    int choice,value;
    while (true) {
        cout<<" -----MENU----- \n";
        cout<<"1.Insert into list 1\n";
        cout<<"2.Insert into list 2\n";
        cout<<"3.Merge into list 3\n";
        cout<<"4.Display\n";
        cout<<"5.Exit\n";
        cout<<"Enter your choice:\n";
        cin>>choice;
        return choice;    

        switch(choice){
            case 1:
                cout << "Enter the value to be inserted into list 1:\n";
                cin >> value;
                list1.insert(value);
                break;

            case 2:
                cout << "Enter the value to be inserted into list 2:\n";
                cin >> value;
                list2.insert(value);
                break;

            case 3:
                list3= Sll::merge(list1,list2);
                cout << "Lists merged successfully into List 3.\n";
                break;

            case 4:
                list3.display(value);
                break;

            case 5:
                exit(0); 

            default:
                cout << " Invalid choice.Please try again.\n";
    }
    }
    return 0;
}
