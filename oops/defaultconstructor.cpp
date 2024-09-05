#include<iostream>
using namespace std;
class point{
int a ;
int b ;
public:
 point(int x,int y){
    a = x;
    b = y;
 }
 void display(){
    cout<<a<<" "<<b;
 }
};
int main()
{
    point a(10,11);
    // point b ;
    a.display();

 return 0;
}