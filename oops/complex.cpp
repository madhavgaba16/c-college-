
#include<iostream>
using namespace std;
class complex{

   float real ;
     float imaginary;
    public:
    complex sum(complex a , comblex b ){
        complex c3;
       c3.real = a.real +b.real;
       c3.imaginary = a.imaginary+b.imaginary
       return c3;
    }
}
int main()
{
    complex a;
    complex b ;
  complex c3= sum(a,b);
 return 0;
}