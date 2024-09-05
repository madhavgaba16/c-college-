// in hybrid inheritance when one grand father class is same then we have to use keyword virtual so that double inhertied are stoped
#include <iostream>
using namespace std;
class student
{
protected:
    int rollnumber;
    int grade;

public:
    void setrollnumber(int r)
    {
        rollnumber = r;
    }
    void setgrade(int s)
    {
        grade = s;
    }
};
class test : virtual public student// here we make student class virtual because result class can recieve student from two side
{
protected:
    float maths;
    float physics;

public:
    void setmaths(int r)
    {
        maths = r;
    }
    void setphysics(int s)
    {
        physics = s;
    }
};
class sports :virtual    public student//here we make student class virtual
{
protected:
    int score;

public:
    void setscrore(int r)
    {
        score = r;
    }
};
class result : public sports, public test
{
protected:
    int total;

public:
    display()
    {

        total = maths + physics + score;
        cout << "student rollnumber:";
        cout << rollnumber << endl;
        cout << "student section:";
        cout << grade << endl;
        cout << "student maths marks:";
        cout << maths << endl;
        cout << "student physics marks:";
        cout << physics << endl;
        cout << "student sports score:";
        cout << score << endl;
        cout << "student total score :";
        cout << total << endl;
    }
};

int main()
{
    result madhav;

    madhav.setrollnumber(28);

    madhav.setgrade(11);

    madhav.setmaths(77);
    madhav.setphysics(94);
    madhav.setscrore(9);
    madhav.display();
    return 0;
}