#include<iostream>
using namespace std;
class complex{
    int a ;
    int b ;
    public:
    complex(void){
        {
    a=0;
    b=0;
 }
    }
    void getnumber(){
        cout<<a<<" "<<b<<endl;
    }
};
// complex::complex(){
//     a=0;
//     b=0;
// }
int main()
{
    complex a ;
    a.getnumber();

 return 0;
}