#include<iostream>
#include<math.h>
using namespace std;
class point{

int a ;
int b ;
    public:
point(int x , int y ){
    a=x;
    b = y ;

}

 void display(){
    cout<<a<<" "<<b;
 }
 friend int distance(point a1 , point b1 );
};
int distance(point a1 ,point b1){
    int ans = sqrt((b1.a*b1.a - a1.a*a1.a)+(b1.b*b1.b - a1.b*a1.b));
    return ans;
}
int main()
{
    point a(10 ,11);
   point b (20,21);
   int ans = distance(a ,b);
   cout<<ans<<endl;

 return 0;
}