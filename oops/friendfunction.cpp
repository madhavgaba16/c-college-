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
friend int sumC(complex a ,complex b);
}
 int sumC (complex a ,complex b){
    return a.a+b.a;
 }

int main()
{
    int sum ;
    complex m ;
    complex a;
    m.setnumber(1,2);
    a.setnumber(2,3);
    sum = sumC(m,a);
    cout<< sum<<endl;
 return 0;
}