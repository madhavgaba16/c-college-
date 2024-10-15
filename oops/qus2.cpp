#include<iostream>
using namespace std;

class A{
    public:
    A(){
        cout<<"a"<<endl;
    }
    ~A(){
        cout<<"eff a";
    }
};
int main()
{
   A obj;
   cout<<"mid"<<endl;

}
