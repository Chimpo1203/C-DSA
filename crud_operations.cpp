#include<bits/stdc++.h>
using namespace std;

struct Tree{

int data;
Tree* left;
Tree* right;
Tree(int x):data(x),left(nullptr),right(nullptr){};
};


void insert(Tree* &root,int key){
    if(root==nullptr){
        root=new Tree(key);
        return;
    }
    if(key<root->data)
        insert(root->left,key);
    else
        insert(root->right,key);

}
void insert_iter(Tree * &root,int key){

Tree* curr=root;
Tree* parent=NULL;

if(root==nullptr)
{
    root=new Tree(key);
    return;
}

while(curr!=nullptr){

    parent=curr;

    if(key>parent->data)
        curr=curr->right;
    else
        curr=curr->left;
}

if(key<parent->data)
    parent->left=new Tree(key);
else
    parent->right=new Tree(key);


}
void traversal(Tree *root){
if(root==nullptr)
    return;
traversal(root->left);
cout<<root->data<<" ";
traversal(root->right);
}
void search(Tree *root,int key,Tree*parent){
if(root==nullptr){
    cout<<"\nI cant found "<<key<<" in tree\n";
    return;
}
//if i found the value;
if(root->data==key){
    if(parent==nullptr){
        cout<<"\nFound the key "<<key<<" at root node\n";
    }
    else if(parent->data>key)
        cout<<"\nFound the key "<<key<<" at left subtree\n";
    else
        cout<<"\nFound the key "<<key<<" at right subtree\n";
    return;
}

if(root->data<key)
    search(root->right,key,root);
else
    search(root->left,key,root);

}




int main(){

int keys[]={15,10,20,8,12,16,25};

Tree *root=nullptr;

for(int y:keys)
    insert_iter(root,y);


traversal(root);
search(root,0,nullptr);


}
