#include<iostream>
using namespace std;
class example{
    public:
    static int  data;
    static void display(){
        cout<<data<<endl;    
    }

};
int example::data=1;


int main()
{
    example a ;
  a.data =10 ;
  example::display();
   example b ;
  b.data =20 ;
  
   example::display();
 return 0;
}