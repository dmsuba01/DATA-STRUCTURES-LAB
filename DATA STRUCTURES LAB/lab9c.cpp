//Different orders of Tree Traversal
// Preorder, Inorder, Postorder
#include <iostream>
using namespace std;

class tree {
private:
    struct node {
        int data;
        struct node* left;
        struct node* right;
    }*root;

public:
    tree() {
        root = nullptr;
    }

    void insert(int value);
    void preorder(node* root);
    void inorder(node* root);
    void postorder(node* root);
    bool search(node* root, int key);
    int getmenu(int choice);
    node *getroot() {
        return root;
    }
};

int main() {
    tree t;
    int choice, value, key;

    while (true) {
        choice = t.getmenu(0); // Get user choice

        switch (choice) {
        case 1:
            cout << "Enter the value to be inserted: ";
            cin >> value;
            t.insert(value);
            break;

        case 2:
            cout << "Preorder Traversal: ";
            t.preorder(t.getroot());
            cout << endl;
            break;

        case 3:
            cout << "Inorder Traversal: ";
            t.inorder(t.getroot());
            cout << endl;
            break;

        case 4:
            cout << "Postorder Traversal: ";
            t.postorder(t.getroot());
            cout << endl;
            break;

        case 5:
            cout << "Enter the value to search: ";
            cin >> key;
            if (t.search(t.getroot(), key))
                cout << key << " is found in the tree.\n";
            else
                cout << key << " is not found in the tree.\n";
            break;

        case 6:
            exit(0);

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}

// Function for the menu
int tree::getmenu(int choice) {
    cout << "\n----- MENU -----\n";
    cout << "1. Insert\n";
    cout << "2. Preorder\n";
    cout << "3. Inorder\n";
    cout << "4. Postorder\n";
    cout << "5. Search\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

// Function to insert a value
void tree::insert(int value) {
    struct node* newnode = new node();
    newnode->data = value;
    newnode->left = newnode->right = nullptr;

    if (root == nullptr) {
        root = newnode;
        cout << value << " inserted into the tree.\n";
        return;
    }

    node* temp = root;
    node* parent = nullptr;

    while (temp != nullptr) {
        parent = temp;
        if (value < temp->data)
            temp = temp->left;
        else if (value > temp->data)
            temp = temp->right;
        else {
            cout << "Duplicate values are not allowed!\n";
            return;
        }
    }

    if (value < parent->data)
        parent->left = newnode;
    else
        parent->right = newnode;

    cout << value << " inserted into the tree.\n";
}

// Preorder traversal
void tree::preorder(node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder traversal
void tree::inorder(node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Postorder traversal
void tree::postorder(node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

// Search function
bool tree::search(node* root, int key) {
    if (root == nullptr)
        return false;
    if (root->data == key)
        return true;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}
