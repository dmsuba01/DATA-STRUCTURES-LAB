//Queue ADT-Array Implementation
#include<iostream>
using namespace std;

#define SIZE 5

class queue{
    private:
        int arr[SIZE];
        int front,rear;

    public:
        queue(){
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

//Function to check full queue
bool queue::isFull(){
    return rear = SIZE - 1;
}

//Function to check empty queue
bool queue::isEmpty(){
    return front == -1 || front > rear;
}

//Function for enqueue
void queue::enqueue(int value){
   if(rear == 4){
    cout << " Queue is Full ! Cannot be enqueued.\n ";
    return;
   }
   if(front == -1){
    front = 0;
   }
   arr[++rear] = value;
   cout << value << " enqueued into the queue.\n ";
}

//Function for dequeue
void queue::dequeue(){
   if(isEmpty()){
     cout << " Queue is empty! Cannot be dequeued.\n  ";
     return; 
   }
   cout << arr[front] << " dequeued from the queue.\n  ";
   front++;
}

//Function for peek
void queue::peek(){
    if(isEmpty()){
        cout << " Queue is empty! Nothing to peek.\n  ";
        return;
    }
    cout << " Front element: " << arr[front];
}