#include<iostream>
using namespace std;
class Node{
    public:
    int data ;
    Node *left;
    Node *right;
    Node(int x ){
        data = x;
        left = right = NULL ;
    }
}
Node * insert (Node *root, int target){
    if(!root) 
    Node * temp = new NOde(target);
     return temp;
    if(target <root->data){
        root ->left = insert(root->left, target);

    }
    else{
         root ->right = insert(root->right, target);
    }
    return root ;
    
}
int main()
{
 return 0;
}