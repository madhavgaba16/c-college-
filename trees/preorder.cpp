//node then left all then right ;
#include<iostream>
using namespace std;
class Node{
    public:
    int data ;
    Node* left;
    Node* right;
    Node(int value){
        data = value;
        left = NULL ;
        right = NULL ;
    }
}
void preorder(Node* root){
    cout<<root->data;
    if(root==NULL) return ;
    prorder(root->left);
    preorder(root->right);

}
void inorder(Node* root){
     if(root==NULL) return ;
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}
void postorder(Node*root){
     if(root==NULL) return ;    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data;

}
int main()
{
 return 0;
}