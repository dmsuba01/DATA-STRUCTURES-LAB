//QUADRATIC PROBING
#include<iostream>
using namespace std;

const int TS = 19;
const int  DELETED = -2;
const int  EMPTY = -1;

class Hashtable{
    private:
        int table[TS];
        int hashfunction(int key){
            return key % TS;
        }

    public:
        Hashtable(){
            for(int i = 0 ; i < TS ; i++){
                table[i] = EMPTY;
            }
        }    
            void insert(int key);
            void remove(int key);
            void search(int key);
            void display();
            int getmenu(int choice);
        

};

int main()
{
    Hashtable ht;
    int choice;
    int key;
    while (true) {
        choice = ht.getmenu(choice);

        switch(choice){
            case 1:
                cout << "Enter the key to be inserted :\n";
                cin >> key;
                ht.insert(key);
                break;

            case 2:
                cout << "Enter the key to be deleted :\n";
                cin >> key ;
                ht.remove(key);
                break;
  
                
            case 3:
                cout << "Enter the key to be searched :\n";
                cin >> key;
                ht.search(key);
                break;

            case 4:
                ht.display();
                break;    
     
            case 5:
                exit(0);

            default:
                cout << " Invalid choice.Please try again.\n";
    }
    }
    return 0;
}

//Function for the menu
int Hashtable::getmenu(int choice){
    cout<<"\n -----MENU----- \n";
    cout<<"1.Insert\n";
    cout<<"2.Remove\n";
    cout<<"3.Search\n";
    cout<<"4.Display\n";
    cout<<"5.Exit\n";
    cout<<"Enter your choice:\n";
    cin>>choice;
    return choice;
}

//Function to Insert 
void Hashtable::insert(int key){
    int index = hashfunction(key);
    int i = 0;
    while(i<TS){
        if( table[index] == DELETED || table[index] == EMPTY ){
            table[index] = key;
            cout << "Inserted " << key << " at index " << index ;
            return;
        }
        index = (index + i*i) % TS;
        i++;
    }
    cout << " Hashtable is Full. Insertion Failed!\n";
}

//Function to Remove 
void Hashtable::remove(int key){
    int index = hashfunction(key);
    int i = 0;
    while(i< TS){
        if( table[index] == EMPTY ){
            cout << "Key" << key << " not found .\n" ;
            return;
        }
        if( table[index] = key ){
            table[index] = DELETED;
            cout << "Key " << key << " at index " << index << " is deleted.\n";
            return;
        }
        index = (index + i*i) % TS;
        i++;
    }
    cout << "Key not found\n";

}

//Function to Search
void Hashtable::search(int key){
    int index = hashfunction(key);
    int i = 0;
    while(i<TS){
        if( table[index] == EMPTY ){
            cout << "Key" << key << " not found .\n" ;
            return;
        }
        if( table[index] = key ){
            cout << "Key " << key << " is found at the index " << index << ".\n";
            return;
        }
        index = (index + i*i) % TS;
        i++;
    }
    cout << "Key not found\n";

}

//Function to Display
void Hashtable::display(){
    cout << "HASHTABLE:\n";
    for(int i = 0;i < TS ; i++){
        if(table[i] == EMPTY){
            cout << i << " : EMPTY\n";
        }
        else if(table[i] == DELETED){
            cout << i << " : DELETED\n";
        }
        else{
            cout << i << " : " << table[i] << "\n";
        }
    }
}
