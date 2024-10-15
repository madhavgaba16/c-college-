#include<iostream>
#include<queue>
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
int main()
{
    int x ;
    cin>>x;
    queue<Node*> q ;
    Node * root = new Node(x);
     q.push(root);
     while(!q.empty()){
        Node *temp = q.front()l
           q.pop();
           cin>>x;
           if(x!=-1){
        temp->left = new Node(x);
        q.push(temp->left)
         }cin>>x
         if(x!=-1){
            temp->right = new Node(x);
             q.push(temp->right);
         }

     }
 return 0;
}