#include <iostream>
#include <string>
using namespace std;

class node
{
    string name;
    int count;
    node* child[50];
    public:
    node* create();
    void display(node*root);
   
};

node* node:: create(){
    node*root;
    node*p;
    root=new node;
    cout<<"enter name of book: ";
    cin>>root->name;
    cout<<"enter the number of chapters: "; 
    cin>>root->count;

    for (int i=0;i<root->count;i++){
        root->child[i]= new node;
        cout<<"enter name of chapter: ";
        cin>>root->child[i]->name;
        cout<<"enter no. of section: ";
        cin>>root->child[i]->count;

        for (int j=0; j<root->child[i]->count;j++){
            root->child[i]->child[j]= new node;
            cout<<"enter name of sections: ";
            cin>>root->child[i]->child[j]->name;
            cout<<"enter no. of subsections: ";
            cin>>root->child[i]->child[j]->count;

            for (int k=0; k<root->child[i]->child[j]->count;k++){
                root->child[i]->child[j]->child[k]= new node;
                cout<<"enter name of subsections: ";
                cin>>root->child[i]->child[j]->child[k]->name;
                root->child[k]=NULL;

            }
        }
    }
    return root;
}

void node:: display(node*root){
    cout<<"book name: "<<root->name;
    for (int i=0;i<root->count;i++){
        cout<<"chapter "<<i<<":"<<root->child[i]->name;
        for (int j=0; j<root->child[i]->count;j++){
            cout<<"     section "<<j<<":"<<root->child[i]->child[j]->name;
            for (int k=0; j<root->child[i]->child[j]->count;j++){
                cout<<"     subsection "<<k<<":"<<root->child[i]->child[j]->child[k]->name;
            }
        }
    }
}
int main(){
    node tree;
    node* Root;
    Root=tree.create();
    tree.display(Root);
    return 0;
}
