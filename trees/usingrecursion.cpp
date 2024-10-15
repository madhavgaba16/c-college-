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
Node* binarytree(){
    int  x ;
    cout<<"enter the data"<<endl;
  cin>>x ;
  if(x==-1) return NULL;
  Node * temp =  new Node(x);
  temp->left = binarytree();
  temp->right = binarytree();
  return temp ;
  
}
int main()
{
 return 0;
}