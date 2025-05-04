//Circular Queue ADT-Array Implementation
#include<iostream>
using namespace std;

#define SIZE 5

class Circularqueue{
    private:
        int arr[SIZE];
        int front,rear;

    public:
        Circularqueue(){
            front = -1;
            rear = -1;
        }
        
        bool isFull();
        bool isEmpty();
        void enqueue(int value);
        void dequeue();
        void peek();
        int getmenu(int choice);

};

int main()
{
    Circularqueue cq;
    int choice;
    int value;
    while (true) {
        choice = cq.getmenu(choice);

        switch(choice){
            case 1:
                cout << "Enter the value to be inserted :\n";
                cin >> value;
                cq.enqueue(value);
                break;

            case 2:
                cq.dequeue();
                break;

            case 3:
                cq.peek();
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
int Circularqueue::getmenu(int choice){
    cout<<"\n -----MENU----- \n";
    cout<<"1.Enqueue\n";
    cout<<"2.Dequeue\n";
    cout<<"3.Peek\n";
    cout<<"4.Exit\n";
    cout<<"Enter your choice:\n";
    cin>>choice;
    return choice;
}

//Function to check full queue
bool Circularqueue::isFull(){
    return (rear + 1) % SIZE == front;
}

//Function to check empty queue
bool Circularqueue::isEmpty(){
    return front == -1;
}

//Function for enqueue
void Circularqueue::enqueue(int value){
   if(rear == 4){
    cout << " Queue is Full ! Cannot be enqueued.\n ";
    return;
   }
   if(front == -1){
    front = rear = 0;
   }
   else{
    rear = (rear + 1) % SIZE;
   }
   arr[rear] = value;
   cout << value << " enqueued into the queue.\n ";
}

//Function for dequeue
void Circularqueue::dequeue(){
   if(isEmpty()){
     cout << " Queue is empty! Cannot be dequeued.\n  ";
     return; 
   }
   cout << arr[front] << " dequeued from the queue.\n  ";
   if(front == rear){
    front = rear = -1;
   }
   else{
    front = (front + 1) % SIZE;
   }
}

//Function for peek
void Circularqueue::peek(){
    if(isEmpty()){
        cout << " Queue is empty! Nothing to peek.\n  ";
        return;
    }
    cout << " Front element: " << arr[front];
}