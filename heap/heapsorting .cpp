#include<iostream>
using namespace std;
class node {
    int data ;
    node next ;
    public:
    node(int num ){
        data = num;
        next= NULL ;

    }
};
class circularlinkedlist{
    node*head;
    public:
    circularlinkedlist(){
        head=NULL;
    }
    void insert(int x){
        node newnode(x);
       if(head==NULL){
        head= newnode;
        head->next = head;
       }
       else{
        node temp = head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
       }
    }
    void display(){
        if(head==NULL){
            cout<<"underflow"<<endl;
        }
        else{
            node temp = head;
        while(temp!=head){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
        cout<<temp->data<<endl;
       }

        }
    };
int main()
{
    circularlinkedlist c;
    c.insert(15);
    c.insert(30);
    c.insert(45);
    c.insert(60);
    c.insert(75);
    c.display();
 return 0;
}