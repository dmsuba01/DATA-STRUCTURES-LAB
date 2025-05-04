//Tree ADT 
#include <iostream>
using namespace std;

class BinaryTree {
private:
    struct Node {
        char data;
        Node *left, *right;
        Node(char value) {
            data = value;
            left = right = nullptr;
        }
    } *root; 

public:
    BinaryTree() {
        root = nullptr;
    }  
    void insert(char value);
    void preorder();
    void inorder();
    void postorder();
    void search(char key);
};

int main() {
    BinaryTree tree;
    int choice;
    char value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a character to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                tree.preorder();
                break;
            case 3:
                tree.inorder();
                break;
            case 4:
                tree.postorder();
                break;
            case 5:
                cout << "Enter a character to search: ";
                cin >> value;
                tree.search(value);
                break;
            case 6:
                exit(0);
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}

//Insert 
void BinaryTree::insert(char value) {
    if (root == nullptr) {
        root = new Node(value);
        return;
    }

    Node* temp = root;
    while (true) {
        char choice;
        cout << "Insert " << value << " to the left (l) or right (r) of " << temp->data << "? ";
        cin >> choice;
        if (choice == 'l') {
            if (temp->left == nullptr) {
                temp->left = new Node(value);
                break;
            } else {
                temp = temp->left;
            }
        } else {
            if (temp->right == nullptr) {
                temp->right = new Node(value);
                break;
            } else {
                temp = temp->right;
            }
        }
    }
}

//Preorder
void BinaryTree::preorder() {
    if (root == nullptr) {
        cout << "Tree is empty.\n";
        return;
    }
    
    Node* stack[100];
    int top = -1;
    stack[++top] = root;

    cout << "Preorder Traversal: ";
    while (top >= 0) {
        Node* node = stack[top--];
        cout << node->data << " ";
        if (node->right) stack[++top] = node->right;
        if (node->left) stack[++top] = node->left;
    }
    cout << endl;
}

//Inorder 
void BinaryTree::inorder() {
    if (root == nullptr) {
        cout << "Tree is empty.\n";
        return;
    }
    
    Node* stack[100];
    int top = -1;
    Node* curr = root;

    cout << "Inorder Traversal: ";
    while (curr != nullptr || top >= 0) {
        while (curr != nullptr) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}

//Postorder 
void BinaryTree::postorder() {
    if (root == nullptr) {
        cout << "Tree is empty.\n";
        return;
    }

    Node* stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;
    cout << "Postorder Traversal: ";
    
    while (top1 >= 0) {
        Node* node = stack1[top1--];
        stack2[++top2] = node;
        if (node->left) stack1[++top1] = node->left;
        if (node->right) stack1[++top1] = node->right;
    }
    
    while (top2 >= 0) {
        cout << stack2[top2--]->data << " ";
    }
    cout << endl;
}

//Search
void BinaryTree::search(char key) {
    Node* temp = root;
    while (temp != nullptr) {
        if (temp->data == key) {
            cout << key << " is found in the tree.\n";
            return;
        }
        temp = (key < temp->data) ? temp->left : temp->right;
    }
    cout << key << " is not found in the tree.\n";
}
