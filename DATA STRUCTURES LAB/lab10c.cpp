//Priority Heap Max
#include<iostream>
#include<vector>

using namespace std;

class Maxheap{
    private:
        vector<int> heap;
        void heapifyUp(int index);
        void heapifyDown(int index);

    public:
       Maxheap(){ }
        void insert(int value);
        void deletemax();
        void display();
        bool search(int value);
        void sort();
        int getmenu(int choice);
     
};

int main()
{
    Maxheap ph;
    int choice;
    int value;
    while (true) {
        choice = ph.getmenu(choice);

        switch(choice){
            case 1:
                cout << "Enter the value to be inserted :\n";
                cin >> value;
                ph.insert(value);
                cout << value << " is inserted in the heap.\n";
                break;

            case 2:
                ph.deletemax();
                break;

            case 3:
                ph.display();
                break;  
                
            case 4:
                cout << "Enter the value to be searched :\n";
                cin >> value;
                if(ph.search(value)){
                   cout << value << " found in the heap. \n";
                }
                else{
                   cout << value << " not found in the heap. \n"; 
                }
                break;

            case 5:
                ph.sort();
                break;     

            case 6:
                exit(0);

            default:
                cout << " Invalid choice.Please try again.\n";
    }
    }
    return 0;
}

//Function for the menu
int Maxheap::getmenu(int choice){
    cout<<"\n -----MENU----- \n";
    cout<<"1.Insert\n";
    cout<<"2.Delete\n";
    cout<<"3.Display\n";
    cout<<"4.Search\n";
    cout<<"5.Sort\n";
    cout<<"6.Exit\n";
    cout<<"Enter your choice:\n";
    cin>>choice;
    return choice;
}

//Function for Heapify Up
void Maxheap::heapifyUp(int index){
    while(index > 0 && heap[index] > heap[(index-1)/2]){
        swap(heap[index],heap[(index-1)/2]);
        index = (index-1)/2;
    }
}

//Function for Heapify Down
void Maxheap::heapifyDown(int index){
    int size = heap.size();
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if(left < size && heap[left] > heap[largest]){
        largest = left;
    }
    if(right < size && heap[right] > heap[largest]){
        largest = right;
    }
    if(largest != index){
        swap(heap[index],heap[largest]);
        heapifyDown(largest);
    }
}

//Function for Insert
void Maxheap::insert(int value){
    heap.push_back(value);
    heapifyUp(heap.size()-1);
}

//Function for Delete
void Maxheap::deletemax(){
    if(heap.empty()){
        cout << " Heap is empty! \n";
        return;
    }
    cout << " Delete Max Element: " << heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
}

//Function for Display
void Maxheap::display(){
    if(heap.empty()){
        cout << " Heap is empty! \n";
        return;
    }
    cout << " Heap elements: \n";
    for(int val : heap){
        cout << val << " ";
    }
    cout << endl;
}

//Function for Search
bool Maxheap::search(int value){
    for(int val : heap){
        if(val == value){
            return true;
        }    
    }   
    return false;
}

//Function for Sort
void Maxheap::sort(){
    vector <int> temp = heap;
    int n = temp.size();
    for( int i = n-1 ;i >= 0 ; i--){
        swap(temp[0],temp[i]);
        heapifyDown(0);
    }
    cout << " Sorted elements: \n";
    for(int val : temp){
        cout << val << " ";
    }
    cout << endl;
}