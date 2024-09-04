#include <iostream>
using namespace std;
class employee
{
    int id;
    static int count;

public:
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
int employee::count=1001
;

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

}