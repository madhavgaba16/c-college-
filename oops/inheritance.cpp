#include <iostream>
using namespace std;

class grandfather {
    string color;
    int money;

public:
    grandfather(){

    }
    grandfather(string r, int n) : color(r), money(n) {}

    void setcolor(const string& r) {
        color = r;
    }
    void setmoney(int n) {
        money = n;
    }
    void getcolor() const {
        cout << color << endl;
    }
    void getmoney() const {
        cout << money << endl;
    }
};

class father : public grandfather {
    string job;
    int carnumber;

public:
  //    x Constructor for father
     father(string r, int n) : grandfather(r, n), job(""), carnumber(0) {}

    void setjob(const string& r) {
        job = r;
    }
    void setcarnumber(int n) {
        carnumber = n;
    }
    void getjob() const {
        cout << job << endl;
    }
    void getcarnumber() const {
        cout << carnumber << endl;
    }
};

class child : public father {
public:
    int age;

    // Constructor for child
    // child() : father("brown", 1000), age(0) {}
};

int main() {
    child s;
    s.age = 11;
    s.setjob("business");
    s.setcarnumber(6070);
    
    s.getcarnumber();
    cout << s.age << endl;
    s.setcolor("fair");
    s.setmoney(1000);
    s.getcolor();
    s.getmoney();
    return 0;
}
