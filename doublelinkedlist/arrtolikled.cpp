#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next ;
     node* prev;
     node(int value){
        data = value;
        next = NULL;
        prev = NULL;
        
     }
};
node* arrtolinkedlistusingrec(int arr[],int size,int index,node* back){
    if(index==size){
        return NULL;

    }
    node* temp =  new node(arr[index]);
    temp->prev = back;
    temp->next=arrtolinkedlistusingrec(arr[], size, index+1,temp);
    return temp;
}

int main()
{
    node
 return 0;
}