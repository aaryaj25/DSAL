#include<iostream>
#include<cstring>
using namespace std;

struct node{
    char data;
    node* left;
    node* right;
};

class tree{
    char prefix[20];
    public:
        node* top;
        void expression(char[]);
        void display(node *);
        void non_rec_postorder(node *);
        void del(node *);
};

class stack1{
    node* data[30];
    int top;
    
    public:
        stack1(){
            top = -1;
        }
        int empty(){
            if(top == -1) return 1;
            else return 0;
        }
        void push(node* p){
            data[++top] = p;
        }
        node* pop(){
            return data[top--];
        }
};        

void tree::expression(char expr[]){
    char c;
    stack1 s;
    node* t1, *t2;
    int len = strlen(expr);
    for(int i = len - 1; i >= 0; i--){
        node* newNode = new node;
        newNode->left = NULL;
        newNode->right = NULL;

        if(isalpha(expr[i])){  // If it's an operand
            newNode->data = expr[i];
            s.push(newNode);
        }
        else if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/'){  // If it's an operator
            t2 = s.pop();  // Right child
            t1 = s.pop();  // Left child
            newNode->data = expr[i];
            newNode->left = t1;
            newNode->right = t2;
            s.push(newNode);
        }
    }
    top = s.pop();  // The root of the expression tree
}

void tree::display(node* root){
    if(root != NULL){
        cout << root->data;
        display(root->left);
        display(root->right);
    }
}

void tree::non_rec_postorder(node* root){
    stack1 s1, s2;
    node* T;
    cout << "\nPostorder traversal (non-recursive): ";
    if(root == NULL) return;

    s1.push(root);
    while(!s1.empty()){
        T = s1.pop();
        s2.push(T);
        if(T->left != NULL) s1.push(T->left);
        if(T->right != NULL) s1.push(T->right);
    }

    while(!s2.empty()){
        T = s2.pop();
        cout << T->data;
    }
}

void tree::del(node* node){
    if(node == NULL) return;
    del(node->left);
    del(node->right);
    cout << endl << "Deleting node: " << node->data << endl;
    delete node;  // Use delete in C++ for dynamic memory
}

int main(){
    char expr[20];
    tree t;
    cout << "Enter Prefix Expression: ";
    cin >> expr;
    cout << "\nPrefix Expression: " << expr << endl;
    
    t.expression(expr);
    
    cout << "Preorder traversal of the expression tree: ";
    t.display(t.top);
    cout << "\n";

    t.non_rec_postorder(t.top);

    t.del(t.top);
    t.top = NULL;  // Ensure top is NULL after deletion

    return 0;
}

