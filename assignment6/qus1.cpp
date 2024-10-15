#include <iostream>
using namespace std;

class CompileTimePolymorphism {
public:
    // Function overloading: same function name but different parameters
    void display(int x) {
        cout << "Display function with int: " << x << endl;
    }

    void display(double x) {
        cout << "Display function with double: " << x << endl;
    }

    void display(string x) {
        cout << "Display function with string: " << x << endl;
    }
};

int main() {
    CompileTimePolymorphism obj;

    // Calling overloaded functions
    obj.display(10);        // Calls display(int)
    obj.display(5.5);       // Calls display(double)
    obj.display("Hello");   // Calls display(string)

    return 0;
}

#include <iostream>
using namespace std;

// Base class
class Parent {
public:
    // Virtual function to enable runtime polymorphism
    virtual void show() {
        cout << "This is the parent class." << endl;
    }
};

// Derived class
class Child : public Parent {
public:
    // Overriding the base class function
    void show() override {
        cout << "This is the child class." << endl;
    }
};

int main() {
    Parent *ptr;
    Parent parentObj;
    Child childObj;

    // Pointing to Parent object
    ptr = &parentObj;
    ptr->show();  // Calls Parent's version of show()

    // Pointing to Child object
    ptr = &childObj;
    ptr->show();  // Calls Child's version of show() (runtime polymorphism)

    return 0;
}
