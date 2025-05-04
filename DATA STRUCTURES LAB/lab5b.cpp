//CIRCULAR LINKED LISTS
#include<iostream>
using namespace std;

class CLL {
    private:
       struct node {
            int data;
            struct node* next; 
       }*head;

    public:
        CLL() {
            head = nullptr;
        }

        void insertbegin(int value);
        void insertend(int value);
        void insertpos(int value, int position);
        void deletebegin();
        void deleteend();
        void deletepos(int position);
        void display();
        bool search(int value);  
        int getmenu(); 
};

int main() {
    CLL cll;
    int choice, value, position;

    while (true) {
        choice = cll.getmenu();

        switch(choice) {
            case 1:
                cout << "Enter the value to be inserted :\n";
                cin >> value;
                cll.insertbegin(value);
                cll.display();
                break;

            case 2:
                cout << "Enter the value to be inserted :\n";
                cin >> value;
                cll.insertend(value);
                cll.display();
                break;

            case 3:
                cout << "Enter the value to be inserted :\n";
                cin >> value;
                cout << "Enter the position :\n";
                cin >> position;
                cll.insertpos(value, position);
                cll.display();
                break;

            case 4:
                cll.deletebegin();
                cll.display();
                break;

            case 5:
                cll.deleteend();
                cll.display();
                break;

            case 6:
                cout << "Enter the position :\n";
                cin >> position;
                cll.deletepos(position);
                cll.display();
                break;

            case 7:
                cll.display();
                break;

            case 8:
                cout << "Enter the value to be searched :\n";
                cin >> value;
                if(cll.search(value)) {
                    cout << "Value found" << endl;
                } else {
                    cout << "Value not found" << endl;
                }
                break;

            case 9:
                exit(0);

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}

// Function for the menu
int CLL::getmenu() {
    int choice;
    cout << " -----MENU----- \n";
    cout << "1. Insert at the Beginning\n";
    cout << "2. Insert at the End\n";
    cout << "3. Insert at the Position\n";
    cout << "4. Delete at the Beginning\n";
    cout << "5. Delete at the End\n";
    cout << "6. Delete at the Position\n";
    cout << "7. Display\n";
    cout << "8. Search\n";
    cout << "9. Exit\n";
    cout << "Enter your choice:\n";
    cin >> choice;
    return choice;
}

// Function to insert at the Beginning
void CLL::insertbegin(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    
    if (head == nullptr) {  // Empty list case
        newnode->next = newnode; // Points to itself, circular link
        head = newnode;
    } else {  // Non-empty list case
        struct node* temp = head;
        
        // Traverse to the last node
        while (temp->next != head) {
            temp = temp->next;
        }
        
        temp->next = newnode;  // Link last node to the new node
        newnode->next = head;  // New node points to the head
        head = newnode;        // Update head to the new node
    }
}

// Function to insert at the End
void CLL::insertend(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;

    if (head == nullptr) {  // Empty list case
        newnode->next = newnode; // Points to itself, circular link
        head = newnode;
    } else {  // Non-empty list case
        struct node* temp = head;
        
        // Traverse to the last node
        while (temp->next != head) {
            temp = temp->next;
        }
        
        temp->next = newnode;  // Last node points to the new node
        newnode->next = head;  // New node points to the head
    }
}

// Function to insert at a specific Position
void CLL::insertpos(int value, int position) {
    if (position == 1) {
        insertbegin(value);
        return;
    }
    
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    struct node* temp = head;

    for (int i = 1; i < position - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    if (temp->next == head && position != 1) {
        cout << "Position is out of bound" << endl;
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

// Function to delete at the Beginning
void CLL::deletebegin() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    struct node* temp = head;

    if (head->next == head) {  // Only one node in the list
        head = nullptr;
    } else {
        struct node* last = head;
        // Traverse to the last node
        while (last->next != head) {
            last = last->next;
        }

        head = head->next;  // Move head to the next node
        last->next = head;  // Last node points to the new head
    }

    delete temp;
}

// Function to delete at the End
void CLL::deleteend() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    struct node* temp = head;
    struct node* prev = nullptr;

    if (head->next == head) {  // Only one node in the list
        head = nullptr;
    } else {
        while (temp->next != head) {  // Traverse to the last node
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;  // Second last node points to the head
    }

    delete temp;
}

// Function to delete at a specific Position
void CLL::deletepos(int position) {
    if (position == 1) {
        deletebegin();
        return;
    }

    struct node* temp = head;
    struct node* prev = nullptr;
    for (int i = 1; i < position && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == head && position != 1) {
        cout << "Position is out of bound" << endl;
        return;
    }

    if (temp == head) {
        deletebegin();
        return;
    }

    prev->next = temp->next;
    delete temp;
}

// Function to display the list
void CLL::display() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    struct node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(head)\n";
}

// Function to search for a value
bool CLL::search(int value) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return false;
    }

    struct node* temp = head;
    do {
        if (temp->data == value) {
            cout << "Value found.\n";
            return true;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Value not found.\n";
    return false;
}
