//List ADT-Array Implementation
#include<iostream>
using namespace std;

class List{
    private:
        int arr[5];
        int size;

    public:
        int current;
        List() : size(0), current(-1){}
        
        //Function for Insert at the Beginning
        void insertbegin(int value){
            if (size == 5){
                cout << "List is full.\n";
                return;
            }

            for(int i = size;i>0;i--){
                arr[i]=arr[i-1];
            }
            arr[0]=value;
            size++;
            current=0;
        }

        //Function for Insert at the End
        void insertend(int value){
            if (size == 5){
                cout << "List is full.\n";
                return;
            }
            arr[size++] = value;
            current = size - 1;
        }

        //Function for Insert at the Position
        void insertpos(int value,int position){
            if (size == 5){
                cout << "List is full.\n";
                return;
            } 
            if( position < 1 || position > size + 1 ){
                cout << " Invalid position.\n";
                return;
            }
            for(int i = size;i >= position;i--){
                arr[i]=arr[i-1];
            }
            arr[position - 1] = value;
            size++;
            current = position -1;
        }

        //Function for Delete at the Beginning
        void deletebegin(){
            if (size == 0){
                cout << "List is empty.\n";
                return;
            }
            for(int i=0;i < size -1 ; i++){
                arr[i] = arr[i+1];
            }
            size--;
            current = 0;
        }

        //Function for Delete at the End
        void deleteend(){
            if (size == 0){
                cout << "List is empty.\n";
                return;
            }
            size--;
            current = size - 1;
        }
        
        //Function for Delete at the Position
        void deletepos(int position){
             if (size == 0){
                 cout << "List is empty.\n";
                 return;
             }
             if( position < 1 || position > size ){
                cout << " Invalid position.\n";
                return;
            }
            for(int i = position - 1;i < size -1 ; i++){
                arr[i] = arr[i+1];
            }
            size--;
            current = position - 1;
        }

        //Function for Display
        void display(){
            if (size == 0){
                cout << "List is empty.\n";
                return;
            }
            for (int i=0;i < size;i++){
                cout << arr[i] << "  ";
            } 
            cout << endl;
        }

        //Function for Search
        void search(int value){
            for(int i = 0;i < size; i++){
               if (arr[i] == value){
                cout << " Element " << value << " found at the position " << i+1 << endl;
                current = i;
                return;
                }
            }
            cout << "Element " << value << " not found.\n" << endl;
        }

        //Function for Rotate using an extra array
        void rotExtraArray(int k){
             if (size == 0){
                cout << "List is empty.\n";
                return;
            }
            int temp[5];
            for(int i=0;i<size;i++){
                temp[(i+k)% size] = arr[i];
            }
            for(int i=0;i<size;i++){
                arr[i] = temp[i];
            }
            current = (current + k ) % size;
        }
        
        //Function for Rotate one at a time
        void rotOneAtATime(int k){
             if (size == 0){
                cout << "List is empty.\n";
                return;
            }
            for(int i=0;i <k;i++){
                int temp = arr[size - 1];
                for(int j = size - 1;j>0;j--){
                    arr[j] = arr[j-1];
                }
                arr[0] = temp;
            }
            current = (current - k + size ) % size;
        }
        
        //Function for Rotate In Place
        void rotInPlace(int k){
             if (size == 0){
                cout << "List is empty.\n";
                return;
            }
            k = k % size;
            reverse(arr,0,size -1);
            reverse(arr,0,k-1);
            reverse(arr,k,size -1);
            current = (current - k + size ) % size;
        }
        
        //Function to reverse
        void reverse(int arr[],int start,int end){
            while(start < end){
                int temp = arr[start];
                arr[start] = arr[end];
                arr[end] = temp;
                start++;
                end--;
            }
        }
};

//Function for the menu
int getmenu(){
    int choice;
    cout<<" -----MENU----- \n";
    cout<<"1.Insert at the Beginning\n";
    cout<<"2.Insert at the End\n";
    cout<<"3.Insert at the Position\n";
    cout<<"4.Delete at the Beginning\n";
    cout<<"5.Delete at the End\n";
    cout<<"6.Delete at the Position\n";
    cout<<"7.Display\n";
    cout<<"8.Search\n";
    cout<<"9.Rotate\n";
    cout<<"10.Exit\n";
    cout<<"Enter your choice:\n";
    cin>>choice;
    return choice;
}

int main()
{
    List list;
    int choice,value,k,position;
    
    while(true) {
        choice = getmenu();

        switch(choice){
            case 1:
                cout << "Enter the value to be inserted :\n";
                cin >> value;
                list.insertbegin(value);
                list.display();
                break;

            case 2:
                cout << "Enter the value to be inserted :\n";
                cin >> value;
                list.insertend(value);
                list.display();
                break;

            case 3:
                cout << "Enter the value to be inserted :\n";
                cin >> value;
                cout << "Enter the position :\n";
                cin >> position;
                list.insertpos(value,position);
                list.display();
                break;

            case 4:
                list.deletebegin();
                list.display();
                break;

            case 5:
                list.deleteend();
                list.display();
                break;

            case 6:
                cout << "Enter the position :\n";
                cin >> position;
                list.deletepos(position);
                list.display();
                break;

            case 7:
                list.display();
                break;

            case 8:
                cout << "Enter the value to be searched :\n";
                cin >> value;
                list.search(value);
                list.display();
                break;

            case 9:
                cout << "Enter the number of times to be rotated :\n";
                cin >> k;
                cout << "Select the rotation method:\n1.Extra Array \n2.One at a time\n3.In-Place\n";
                cin >> choice;
                switch(choice){
                    case 1:
                        list.rotExtraArray(k);
                        break;
                    case 2:
                        list.rotOneAtATime(k);
                        break;
                    case 3:
                        list.rotInPlace(k);
                        break;
                    default:
                        cout << "Invalid choice.\n";
                }
                list.display();
                break;

            case 10:
                exit(0);

            default:
                cout << " Invalid choice.Please try again.\n";
        }
    }
    return 0;
}