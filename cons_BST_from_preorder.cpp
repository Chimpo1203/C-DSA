#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
int data;
struct TreeNode *left;
struct TreeNode *right;

TreeNode(int x): data(x),left(nullptr),right(nullptr) {};
};

TreeNode *solve(vector<int> &preorder){
    if(preorder.empty())
        return NULL;
    vector<int>s,g;

    int root=preorder[0];
    TreeNode *r=new TreeNode(root);

    for(int i=1;i<preorder.size();i++){
        if(preorder[i]>root)
            s.push_back(preorder[i]);
        if(preorder[i]<root){
            g.push_back(preorder[i]);
        }
    }

    r->left=solve(g);
    r->right=solve(s);

    return r;
}

void inorder(TreeNode *root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int main(){
    int n;
    cin>>n;

    vector<int> preorder(n,0);

    for(int i=0;i<n;i++)
        cin>>preorder[i];

    TreeNode *result= solve(preorder);
    inorder(result);
}
