#include<iostream>
using namespace std;

class base {
protected:
    int i;
public:
    base() {
        cout << "Constructor called base" << endl;
    }

    base(int x) {
        i = x;
        cout << "Constructor called base, i is set to " << i << endl;
    }
};

class derived : public base {
    int x;
public:
    derived() {
        cout << "Constructor called derived" << endl;
    }

    // Derived constructor that asks whether to set base or derived
    derived(int y) {
        bool a;
        cout << "What do you want to set (1 for base, 0 for derived)?" << endl;
        cin >> a;

        if (a) {
            // Call base class constructor using initializer list
            *this = derived(y, y);  // Delegate to another constructor
        } else {
            x = y;
            cout << "Constructor called derived, derived set with x = " << x << endl;
        }
    }

    // Derived constructor that sets both base and derived
    derived(int y, int f) : base(f) {
        x = y;
        cout << "Constructor called derived, derived set with x = " << x << " and base set with i = " << i << endl;
    }
};

int main() {
    derived obj(10);  // This will ask whether to set base or derived
    return 0;
}