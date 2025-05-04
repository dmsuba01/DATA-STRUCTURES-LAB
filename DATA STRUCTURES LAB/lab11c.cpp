//SEPERATE CHAINING
#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

const int TS = 10;

class Hashtable{
    private:
        list<int> table[TS];
        int hashfunction(int key){
            return key % TS;
        }

    public:
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
    table[index].push_back(key);
    cout << "Inserted " << key << " at index " << index ;
          
}

//Function to Remove 
void Hashtable::remove(int key){
    int index = hashfunction(key);
    list<int>& chain = table[index];
    list<int>::iterator it = find(chain.begin(), chain.end(),key);
        if(it != chain.end()){ 
            chain.erase(it);
            cout << "Key " << key << " at index " << index << " is deleted.\n";
        }
        else{
            cout << "Key not found\n";
        }
}

//Function to Search
void Hashtable::search(int key){
    int index = hashfunction(key);
    list<int>& chain = table[index];
    list<int>::iterator it = find(chain.begin(), chain.end(),key);
        if(it != chain.end()){ 
            cout << "Key " << key << " is found at the index " << index << ".\n";
        }
        else{
            cout << "Key not found\n";
        }
}

//Function to Display
void Hashtable::display(){
    cout << "HASHTABLE:\n";
    for(int i = 0;i < TS ; i++){
       cout << i << " : ";
       for( int key : table[i]){
        cout << key << " -> ";
       }
       cout << " NULL\n ";
        
    }
}