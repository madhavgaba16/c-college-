#include <iostream>
using namespace std;

// Base class
class Parent {
public:
    
  virtual   void show() {
        cout << "This is the parent class." << endl;
    }
};

// Derived class
class Child : public Parent {
public:
   
    // void show() override {
    //     cout << "This is the child class." << endl;
    // }
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
     ptr->show();
     // Calls Child's version of show() (runtime polymorphism)

    return 0;
}