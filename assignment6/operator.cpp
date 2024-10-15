#include<iostream>
using namespace std;

class complex {
    int img;
    int real;
public:
    // Default constructor
    complex() {};

    // Parameterized constructor
    complex(int real, int img) {
        this->real = real;
        this->img = img;
    }

    // Overloading the + operator
    complex operator +(complex C) {
        complex ans;
        ans.real = real + C.real;
        ans.img = img + C.img;
        return ans;
    }

    // Getter methods to access private members
    int getReal() {
        return real;
    }

    int getImg() {
        return img;
    }
};

int  main() {
    complex c1(3, 4);
    complex c2(4, 8);
    cout<< c1 + c2<<endl;
    return 0;
    
 
}

