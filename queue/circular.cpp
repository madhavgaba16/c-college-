#include<iostream>
using namespace std;
class circuralqueue{
    int front;
    int rear;
    int size ;
    int *arr;
    public:
    circuralqueue(int n ){
        arr = new arr[n];
        front = -1 ;
        rear = -1;
    size = n;
    }
    bool isempty(){
       if(front == -1){
        return true ;
       }
       return false;
    }
        bool isfull(){
            if ((rear+1)%size==front){
              return true ;
            }
            return false;
        }   
};
int main()
{
 return 0;
}