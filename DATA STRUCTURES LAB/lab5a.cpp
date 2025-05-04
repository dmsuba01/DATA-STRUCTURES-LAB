//DOUBLY LINKED LIST
#include<iostream>
using namespace std;

class DLL{
    private:
       struct node{
            int data;
            struct node* next;
            struct node* prev; 
       }*head,*tail;
    public:
          DLL(){
               head = nullptr;
               tail = nullptr;
            }  
            void insertbegin(int value);
            void insertend(int value);
            void insertpos(int value,int position);
            void deletebegin();
            void deleteend();
            void deletepos(int position);
            void display(int value);
            bool search(int value);  
            int getmenu(int choice); 
};

int main()
{
    DLL dll;
    int choice,value,position;
    while (true) {
        choice = dll.getmenu(choice);

        switch(choice){
            case 1:
                cout << "Enter the value to be inserted :\n";
                cin >> value;
                dll.insertbegin(value);
                dll.display(value);
                break;

            case 2:
                cout << "Enter the value to be inserted :\n";
                cin >> value;
                dll.insertend(value);
                dll.display(value);
                break;

            case 3:
                cout << "Enter the value to be inserted :\n";
                cin >> value;
                cout << "Enter the position :\n";
                cin >> position;
                dll.insertpos(value,position);
                dll.display(value);
                break;

            case 4:
                dll.deletebegin();
                dll.display(value);
                break;

            case 5:
                dll.deleteend();
                dll.display(value);
                break;

            case 6:
                cout << "Enter the position :\n";
                cin >> position;
                dll.deletepos(position);
                dll.display(value);

                break;

            case 7:
                dll.display(value);
                break;

            case 8:
                cout << "Enter the value to be searched :\n";
                cin >> value;
                if(dll.search(value)) {
                    cout << "Value found" << endl;
                } else {
                    cout << "Value not found" << endl;
                }
                break; 

            case 9:
                exit(0);

            default:
                cout << " Invalid choice.Please try again.\n";
    }
    }
    return 0;
}

//Function for the menu
int DLL::getmenu(int choice){
    cout<<" -----MENU----- \n";
    cout<<"1.Insert at the Beginning\n";
    cout<<"2.Insert at the End\n";
    cout<<"3.Insert at the Position\n";
    cout<<"4.Delete at the Beginning\n";
    cout<<"5.Delete at the End\n";
    cout<<"6.Delete at the Position\n";
    cout<<"7.Display\n";
    cout<<"8.Search\n";
    cout<<"9.Exit\n";
    cout<<"Enter your choice:\n";
    cin>>choice;
    return choice;
}

//Function for Insert at the Beginning
void DLL::insertbegin(int value){
      struct node* newnode = (struct node*)malloc(sizeof(struct node));
      newnode->data = value;
      newnode->prev = nullptr;
      if(head == nullptr){
        newnode->next = nullptr;
        head = newnode;
        tail = newnode;
      }
      else{
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
      }
      
}

//Function for Insert at the End
void DLL::insertend(int value){
      struct node* newnode = (struct node*)malloc(sizeof(struct node));
      newnode->data = value;
      newnode->next = nullptr;
      newnode->prev = tail;
      if(tail != nullptr){
         tail->next = newnode;
      }
      tail = newnode;
      if(head == nullptr){
         head = newnode;
      }
}


//Function for Insert at the Position
void DLL::insertpos(int value,int position){
    if(position == 1){
        insertbegin(value);
        return;
    }
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    node* temp = head;
    for(int i=1;i<position-1 && temp->next != nullptr;i++){
        temp = temp->next;
    }
    if(temp == nullptr){
        cout << "Position is out of bound" << endl;
        return;
    }
    newnode->next = temp->next;
    newnode->prev = temp;
    if(temp->next != nullptr){
        temp->next->prev = newnode;
    }
    temp->next = newnode;
    if(newnode->next == nullptr){
        tail = newnode;
    }
}

//Function for Delete at the Beginning
void DLL::deletebegin(){
    if(head == nullptr){
        cout << "List is empty" << endl;
        return;
    }
    node* temp = head;
    head = head->next;
    if(head != nullptr){
        head->prev = nullptr;
    }
    else{
        tail = nullptr;
    }
    delete temp;
}

//Function for Delete at the End
void DLL:: deleteend(){
    if(tail == nullptr){
        cout << "List is empty" << endl;
        return;
    }
    node* temp = tail;
    tail = tail->prev;
    if(tail != nullptr){
        tail->next = nullptr;
    }
    else{
        head = nullptr;
    }
    delete temp;
}        

//Function for Delete at the Position
void DLL:: deletepos(int position){
    if(position == 1){
        deletebegin();
    }
    node* temp = head;
    for(int i=1;i<position-1 && temp->next != nullptr;i++){
        temp = temp->next;
    }
    if(temp == nullptr){
        cout << "Position is out of bound" << endl;
        return;
    }
    if(temp->next != nullptr){
        temp->next->prev = temp->prev;
    }
    if(temp->prev != nullptr){
        temp->prev->next = temp->next;
    }
    if(temp != nullptr){
        delete temp;
    }
    delete temp;
}


//Function for Display
void DLL::display(int value){ 
    if (head == NULL){
        cout << "List is empty.\n";
        return;
    }
    //forward direction
    node* temp = head;
    while(temp != NULL){
        cout << value << " <=> ";
        temp = temp -> next;
    } 
    cout << "NULL\n";
    //reverse direction
    temp = tail;
    while(temp->prev != nullptr){
        cout << value << " <=> ";
        temp = temp -> prev;
    }
    cout << "NULL\n";
}       

//Function for Search
bool DLL::search(int value){
    node* temp = head;
    while(temp != nullptr){
        if( temp->data == value){
            return true;
        }
        temp = temp->next;
    } 
    return false;
}   












