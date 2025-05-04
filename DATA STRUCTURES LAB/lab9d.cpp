//Tree ADT- Using a constructor
#include <iostream>
#include <stack>
using namespace std;

class tree {
private:
    struct node {
        char value;
        struct node* left;
        struct node* right;

        node(char v) {
            value = v;
            left = right = nullptr;
        }
    } *root;

public:
    tree() {
        root = nullptr;
    }

    void buildTree(string postfix);
    int getmenu(int choice);
    node* getRoot();
    bool isoperator(char c);
    node* constructTree(string postfix);
    void preorder(node* root);
    void inorder(node* root);
    void postorder(node* root);

};

int main() {
    tree t;
    int choice;
    string postfix;

    while (true) {
        choice = t.getmenu(0); // Get user choice

        switch (choice) {
        case 1:
            cout << "Enter a postfix expression: ";
            cin >> postfix;
            break;

        case 2:
            t.buildTree(postfix);
            break;

        case 3:
            cout << "Preorder Traversal: ";
            t.preorder(t.getRoot());
            cout << endl;
            break;

        case 4:
            cout << "Inorder Traversal: ";
            t.inorder(t.getRoot());
            cout << endl;
            break;

        case 5:
            cout << "Postorder Traversal: ";
            t.postorder(t.getRoot());
            cout << endl;
            break;

        case 6:
            exit(0);

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}

// Function for menu
int tree::getmenu(int choice) {
    cout << "\n----- MENU -----\n";
    cout << "1. Enter a postfix expression\n";
    cout << "2. Construct a tree\n";
    cout << "3. Preorder\n";
    cout << "4. Inorder\n";
    cout << "5. Postorder\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

// Checks if a character is an operator
bool tree::isoperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Construct expression tree from postfix expression
tree::node* tree::constructTree(string postfix) {
    stack<node*> st;

    for (char c : postfix) {
        if (!isoperator(c)) {
            st.push(new node(c));
        } else {
            node* rightnewnode = st.top(); st.pop();
            node* leftnewnode = st.top(); st.pop();
            node* newnode = new node(c);
            newnode->left = leftnewnode;
            newnode->right = rightnewnode;
            st.push(newnode);
        }
    }
    return st.top();
}

// Function to build tree from postfix
void tree::buildTree(string postfix) {
    root = constructTree(postfix);
    cout << "Expression tree constructed successfully.\n";
}

// Getter function for root node
tree::node* tree::getRoot() {
    return root;
}

// Preorder traversal
void tree::preorder(node* root) {
    if (root != nullptr) {
        cout << root->value << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Inorder traversal
void tree::inorder(node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }
}

// Postorder traversal
void tree::postorder(node* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->value << " ";
    }
}
