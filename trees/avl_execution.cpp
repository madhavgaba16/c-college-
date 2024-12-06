#include<iostream>
using namespace std;
class Node{
    public:
    int data ;
    Node* left;
    Node* right;
    int height;
    Node(int value){
        data = value;
        height = 1;
        left =right= NULL;
    }
}
Node * rightrotation(Node*root){
    Node*child = root->left;
    Node* childright = child->right;
    child->right = root;
    root->left = childright;
    root->height= 1+max(getheight(root->left),getheight(root->right));
    child->height = 1+max(getheight(root->left),getheight(root->right));
     return child;
}
Node * leftrotation(Node*root){
    Node*child = root->right;
    Node* childleft = child->left;
    child->right = root;
    root->left = childright;
    root->height= 1+max(getheight(root->left),getheight(root->right));
    child->height = 1+max(getheight(root->left),getheight(root->right));
     return child;
}

Node* insert(Node*root, int key){
    if(!root) return new Node(key);

    if(root->data>key){
        root->left = insert(root->left,key);
    }
    else if(key>root->data)
    root->right= insert(root->right,key);
    else 
    return root;
    //update height
    root->height= 1+max(getheight(root->left),getheight(root->right));

    int balance = getbalance(root);
    //leftleft
    if(balance>1&& key <root->left->data){
       return rightrotation(root);
    }
    //rightright
    else if(balance<-1&& key >root->left->data){
      return leftrotation(root);
    }
    //leftright
    else if(balance>1&& key >root->left->data){
      root->left =   leftrotation(root->left);
        return rightrotation(root);
    }

    //right left case 
    else if(balance<-1&&root->right->data>key){
         root->right =  rightrotation(root->right);
      return  leftrotation(root);
    }
    else{
       return root;
    }


}
int getbalance(node*root){
    if(root==NULL) return 0;
    return getheight(root->left)-getheight(root->right);
}
int getheight(Node * root){
    if(!root)
    return 0 ;
    return root->height;
}
int main()
{
    Node*root = NULL;

   root = insert(root,10);
   root = insert(root,20);
   root = insert(root,30);
   root = insert(root,40);
   root = insert(root,5);
   root = insert(root,60);
    root = insert(root,100);

    return 0;
}
