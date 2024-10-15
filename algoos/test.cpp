#include <iostream>
using namespace std;

class ClassA {
public :
    int value;
public:
    // Constructor
    ClassA(int v = 0) : value(v) {}

    // Getter to access value
    int getValue() const {
        return value;
    }

    // Setter to modify value
    void setValue(int v) {
        value = v;
    }
};

class ClassB :public ClassB{
public:
    // Function to accept and process the array of ClassA objects
    void processArray(ClassA* arr, int size) {
        cout << "Values in the ClassA array received by ClassB: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";  // Access value using ClassA's method
        }
        cout << endl;
    }
};

int main() {
    int size = 5;

    // Create an array of ClassA objects in main
    ClassA* classAArray = new ClassA[size];

    // Set values for each ClassA object in the array
    for (int i = 0; i < size; i++) {
        classAArray[i] = ClassA(i);  // Setting arbitrary values like 10, 11, 12, ...
    }

    // Create an object of ClassB
    ClassB b;

    // Pass the array of ClassA objects to the function in ClassB
    b.processArray(classAArray, size);

    // Clean up the dynamically allocated memory
    delete[] classAArray;

    return 0;
}