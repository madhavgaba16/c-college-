#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *next;

};

int main() {
    node *head = new node();
    head->data= 10;
    head->next=NULL;
    cout<< head->data;

    return 0;
}