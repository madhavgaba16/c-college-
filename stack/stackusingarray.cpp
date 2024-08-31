#include<iostream>
using namespace std;
class stackusingarray{
    int *arr;
    int size;
    int top = -1;
    public:
    stack(int s){
        arr = new arr[s];
        size = s;
        top = -1;
    }
    void push(int data){
        if(top = size-1){
            cout<<"stack overflow"<<endl;
            }
            else{
                top++;
                arr[top]= data;
                }
    }
    void pop(){
        if(top ==-1){
            cout<<"stack underflow"<<endl;
        }
        else
        top--;
    }
    bool isempty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    int peek(){
        if(top==-1){
            return -1;
        }
        else{
            return arr[top];
        }
    }
    int issize(){
        return top+1;
    }
}
int main (){

}