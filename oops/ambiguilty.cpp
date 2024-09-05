#include<iostream>
using namespace std;
class base1{
public:
 void great(){
    cout<<"hello "<<endl;
 }
};
class base2{
    public:
    void great(){
        cout<<"yoo"<<endl;
    }
};
class derived:public base1, public base2{
    public:
    // void great(){
    //     cout <<"hell"<<endl; great not present in the class then we have to specify what are we talking about;
    // }
    void great(){
        base1::great();//specifying which class function need to be called 
        }
    int a ;
};
int main()
{
    derived a;
    a.great();//a will call in derived call only if great is not present in the derived class and both base classhave same function then 
    // we have to specify which class we are calling;
    
 return 0;
}