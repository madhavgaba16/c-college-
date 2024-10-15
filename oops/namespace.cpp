#include <iostream>
using namespace std;

// class definition
class A {
  private:
  string name;
  string location;
  
public:
    // static data member
    static int x;
    
    A() { 
      cout << "A's default constructor called" << endl; 
    }

    A(string name1, string address){
      name = name1;
      location = address;
      cout << "A's parameterized constructor called" << endl;
    }

};

// Initializing static data member outside class
int A::x = 0;

class B: public A {
  private:
  string name;
  string location;
  
public:
    // static data member
    static int x;
    
    B() { 
      cout << "B's default constructor called" << endl; 
    }

    B(string name1, string address){
      name = name1;
      location = address;
      cout << "B's parameterized constructor called" << endl;
    }
};

// Initializing static data member outside class
int B::x = 0;

class C: public B {
  private:
  string name;
  string location;
  
public:
    // static data member
    static int x;
    
    C() { 
      cout << "C's default constructor called" << endl; 
    }

    C(string name1, string address, string name2, string address1, string name3, string address2) 
    : A(name2, address1), B(name3, address2) {
      name = name1;
      location = address;
      cout << "C's parameterized constructor called" << endl;
    }
};

// Initializing static data member outside class
int C::x = 0;

// Driver code
int main()
{
    // Create an object of class C
    C c("Man", "Bhag", "Auyds", "Gashfd", "Atyfst", "Asdgy");
    
    // Accessing the static data member using the class name and scope resolution operator
    C::x = 10;
    cout << "Static member C::x = " << C::x << endl;
 
    return 0;
}
