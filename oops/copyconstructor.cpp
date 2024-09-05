#include<iostream>
using namespace std;
class home{
    int size;
    int rate;
    public:
    home(){
        size =0 ;
        rate =0 ;
    }
    home (int x , int y ){
        size  = x;
        rate = y;
    }
    home (int x){
      size = x;
      rate = x*100000;
}
home(const home &obj){
    size = obj.size;
    rate = obj.rate;// necessay to pass copy constructor with & reference variable ;
    // it is best as it does not create a copy of the object but 
}
void display(){
    cout<<rate<<" "<<size<<endl;

}
};
int main()
{
    home a(20 ,1000000);
    home b (a);
    b.display();
 return 0;
}