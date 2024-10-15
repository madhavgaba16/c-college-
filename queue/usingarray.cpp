#include <iostream>
using namespace std;

class queue
{
    int front;
    int rear;
    int *arr;
    int size;

public:
    queue(int n)
    {
        arr = new int[n];
        front = -1;
        rear = -1;
        size = n;
    }
    bool isfull()
    {
        if (rear == size - 1)
        {
            return 1;
        }
        return 0;
    }
    bool isempty()
    {
        if (front == -1)
        {
            return 1;
        }
        return 0;
    }
    void enqueue(int n)
    {
        if (isempty())
        {
            front = 1;
            rear = 1;
            arr[rear] = n;
        }
        else if (rear == size - 1)
        {
            cout << "overflow consdition" << endl;
        }
        else
        {
            rear++;
            arr[rear] = n;
        }
    }
    void dequeue()
    {
        if (isempty())
        {
            cout << "underflow condition" << endl;
        }
        else if (front == rear)
        {

            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }
    int capacity()
    {
        return rear + 1;
    }
    int start(){
        if(isempty()){
            return -1;
        }
        else{
            return arr[front];
        }
    }
};  
int main()
{
    return 0;
}