#include <iostream>
using namespace std;
class employee
{
    int id;
   
public:
 static int count=1000;


    void setid()
    {
        cout << "enter the id of the employee";
        cin >> id;
        count++;
    };
    void getid()
    {
        cout << "id of the employee is" << id << endl;
        cout << "total employee" << count << endl;
    };
};
int employee::count;

int main()
{
    employee m;
    employee a;
    employee b;
    employee c;
    m.setid();
    a.setid();
    b.setid();
    b.getid();
    c.setid();
    m.getid();
   cout<< employee::count;


}