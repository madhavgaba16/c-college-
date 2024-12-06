#include <iostream>
using namespace std;

// Template class A
template <typename T1, typename T2>
class A {
    T1 x;
    T2 y;
public:
    A() {
        // Constructor implementation (optional, can be left empty)
    }
};

int main() {
    // Creating objects of class A with different type parameters
    A<char, char> p;
    A<int, int> q;

    // Displaying the size of the objects
    cout << sizeof(p) << "\t" << sizeof(q);

    return 0;
}
