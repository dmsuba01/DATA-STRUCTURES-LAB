//List ADT-Singly linked list 
#include<iostream>
using namespace std;

class Sll{
    private:
       struct node{
            int data;
            struct node* next; 
       }*head;
    public:
          Sll(){
                head=nullptr;
          }
             int getmenu(int choice);
             void insertbegin(int value);
             void insertend(int value);
             void insertpos(int value,int position);
             void deletebegin();
             void deleteend();
             void deletepos(int position);
             void display(int value);
             int search(int value);
             void displayreverse(node* node);
             void reversedisplay(int value);
             void reverselink(int value);
};

int main()
{
    Sll sll;
    int choice,value,position;
    while (true) {
        choice = sll.getmenu(choice);

        switch(choice){
            case 1:
                cout << "Enter the value to be inserted :\n";
                cin >> value;
                sll.insertbegin(value);
                sll.display(value);
                break;

            case 2:
                cout << "Enter the value to be inserted :\n";
                cin >> value;
                sll.insertend(value);
                sll.display(value);
                break;

            case 3:
                cout << "Enter the value to be inserted :\n";
                cin >> value;
                cout << "Enter the position:\n";
                cin >> position;
                sll.insertpos(value,position);
                sll.display(value);
                break;

            case 4:
                sll.deletebegin();
                sll.display(value);
                break;

            case 5:
                sll.deleteend();
                sll.display(value);
                break;

            case 6:
                cout << "Enter the position:\n";
                cin >> position;
                sll.deletepos(position);
                sll.display(value);
                break;

            case 7:
                sll.display(value);
                break;

            case 8:
                cout << "Enter the value to be searched :\n";
                cin >> value;
                sll.search(value);
                break;

            case 9:
                sll.reversedisplay(value);
                break;

            case 10:
                sll.reverselink(value); 
                sll.display(value);
                break;

            case 11:
                exit(0); 

            default:
                cout << " Invalid choice.Please try again.\n";
    }
    }
    return 0;
}

//Function for the menu
int Sll::getmenu(int choice){
    cout<<" -----MENU----- \n";
    cout<<"1.Insert at the Beginning\n";
    cout<<"2.Insert at the End\n";
    cout<<"3.Insert at the Position\n";
    cout<<"4.Delete at the Beginning\n";
    cout<<"5.Delete at the End\n";
    cout<<"6.Delete at the Position\n";
    cout<<"7.Display\n";
    cout<<"8.Search\n";
    cout<<"9.Display Reverse\n";
    cout<<"10.Reverse Link\n";
    cout<<"11.Exit\n";
    cout<<"Enter your choice:\n";
    cin>>choice;
    return choice;
}

//Function for Insert at the Beginning
void Sll::insertbegin(int value){
      struct node* newnode = (struct node*)malloc(sizeof(struct node));
      newnode->data = value;
      newnode->next = head;
      head = newnode;
}  

//Function for Insert at the End
void Sll::insertend(int value){
      struct node* newnode = (struct node*)malloc(sizeof(struct node));
      newnode->data = value;
      newnode->next = nullptr;
      if (head == nullptr) {
            head = newnode;
            return;
      }
      node* temp = head;
      while(temp->next != nullptr){
        temp = temp->next;
      }
      temp->next = newnode;
}

//Function for Insert at the Position 
void Sll::insertpos(int value,int position){
    if(position <= 0){
        insertbegin(value);
        return;
    }
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    node* temp = head;
    for(int i =0;i<position - 1;++i){
        temp = temp->next;
    }
    if(temp == nullptr || temp->next == nullptr){
        insertend(value);
    }
    else{
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
//Function for Delete at the Beginning
void Sll::deletebegin(){
    if(head == nullptr){
        cout << "List is empty"<<endl;
        return;
    } 
    node* temp = head;
    head=head->next;
    delete temp;
}

//Function for Delete at the End
void Sll::deleteend(){
    if(head == nullptr){
        cout << "List is empty"<<endl;
        return;
    } 
    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }
    node* temp = head;
    while(temp->next != nullptr && temp->next->next != nullptr){
        temp = temp->next;
    }
    temp->next = nullptr;
    delete temp->next;
}

//Function for Delete at the Position  
void Sll::deletepos(int position){
    if(position <= 0){
        deletebegin();
        return;
    }
    node* temp = head;
    for(int i =1;i<position-1 && temp->next != nullptr;++i){
        temp = temp->next;
    }
    if(temp->next != nullptr){
        node* temp1 = temp->next;
        temp->next = temp1->next;
        delete temp1;
    }
}

//Function for Display
void Sll::display(int value){
    if(head == nullptr){
        cout << "List is empty"<<endl;
        return;
    } 
    node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " --> " ;
        temp = temp -> next;
    } 
    cout << " N " << endl;
}

//Function for search
int Sll::search(int value){
    node* temp = head;
    int count = 1;
    while(temp != nullptr){
        if(temp->data == value){
            cout << " Element " << value << " found at the position " << count << endl;
            return 1;
        }
        temp = temp->next;
        count++;
    }
    cout << " Element " << value << " not found at the position " << endl;
    return 0;
}

//Function for recursion
void Sll::displayreverse(node* node){
   if(node == nullptr) return;
   displayreverse(node->next);
   cout << node->data << " ";
}

//Function for Reverse Display
void Sll::reversedisplay(int value){
    if(head == nullptr){
        cout << "List is empty"<<endl;
        return;
    }
    displayreverse(head);
    cout << endl;
}

//Function for Reverse Link
void Sll::reverselink(int value){
    if(head == nullptr){
        cout << "List is empty"<<endl;
        return;
    }
    node* prev = nullptr;
    node* temp = head;
    node* next = nullptr;
    while(temp != nullptr){
          next = temp->next;
          temp->next = prev;
          prev = temp;
          temp = next;
    }
    head = prev;
}