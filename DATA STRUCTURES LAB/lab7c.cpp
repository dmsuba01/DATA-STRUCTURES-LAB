//Queue ADT-Singly linked list
#include<iostream>
using namespace std;

class queue{
    private:
        struct node{
            int data;
            struct node* next; 
       }*front,*rear;

    public:
        queue(){
            front = rear = nullptr;
        }

        bool isEmpty();
        void enqueue(int value);
        void dequeue();
        void peek();
        int getmenu(int choice);

};

int main()
{
    queue q;
    int choice;
    int value;
    while (true) {
        choice = q.getmenu(choice);

        switch(choice){
            case 1:
                cout << "Enter the value to be inserted :\n";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.peek();
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
int queue::getmenu(int choice){
    cout<<"\n -----MENU----- \n";
    cout<<"1.Enqueue\n";
    cout<<"2.Dequeue\n";
    cout<<"3.Peek\n";
    cout<<"4.Exit\n";
    cout<<"Enter your choice:\n";
    cin>>choice;
    return choice;
}

//Function to check empty queue
bool queue::isEmpty(){
    return front == nullptr;
}

//Function for enqueue
void queue::enqueue(int value){
   struct node* newnode = (struct node*)malloc(sizeof(struct node));
   newnode->data = value;
   newnode->next = nullptr;
   if(rear != nullptr){
        rear->next = newnode;
   }
   rear = newnode;
   if(front == nullptr){
        front = newnode;
   }
   cout << value << " enqueued into the queue.\n ";
}

//Function for dequeue
void queue::dequeue(){
   if(front == nullptr){
     cout << " Queue is empty! Cannot be dequeued.\n  " << endl;
     rear = nullptr;
     return; 
   }
   cout << front->data << " dequeued from the queue.\n  ";
   node* temp = front;
   front = front->next;
   delete temp;
}   

//Function for peek
void queue::peek(){
    if(front == nullptr){
        cout << " Queue is empty! Nothing to peek.\n  ";
        return;
    }
    cout << " Front element: " << front->data ;
}