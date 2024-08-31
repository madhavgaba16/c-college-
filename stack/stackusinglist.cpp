#include<iostream>
using namespace std;
class Node{
    public:
    int data ;
    Node * next;
    Node(int data){
        this->data = data;
        next=null;
    }
}
class stackusinglist{
    Node *top;
    int size;
    stackusinglist(){
        top = null;
        size=0;
    }
    void push(int data){
        Node *temp = new Node(data);
        temp->next = top;
        top = temp;
        size++;
    }
void pop(){
    if(size==0){
        cout<<"stack underflow"<<endl;

    }
    else{
    Node *temp = top;
    top = temp->next;
    size--;
    delete temp;
    }
}
int peek(){
    if(top==null){
        cout<<"stack underflow"<<endl;
        return -1;
    }else{
        return top->data;
    }
}
}