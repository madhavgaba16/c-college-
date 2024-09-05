#include<iostream>
using namespace std;
class complex{
int a ;
int b ;
public:
void setnumber(int a1,int b1){
    a= a1;
    b= b1;
}
void getnumber(){
    cout<<"complex number is"<<a<<"+"<<b<<"i"<<endl;
}
void  sum (complex o1,complex o2){
    a = o1.a+o2.a;
    b = o1.b+o2.b;
}


};
int main (){
    complex m;
     complex a;
    m.setnumber(2,5);
    m.getnumber();

    a.setnumber(5,2);
    a.getnumber();
   complex c ;
   c.sum(m,a);
   c.getnumber();

    



}