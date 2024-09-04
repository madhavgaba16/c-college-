#include <iostream>

 class ClassB; 

class ClassA {
private:
    int value;
    
public:
    ClassA(int v) : value(v) {}
    
    // Declare the friend function
    friend void swapValues(ClassA &a, ClassB &b);
    
    void display() const {
        std::cout << "ClassA value: " << value << std::endl;
    }
};

class ClassB {
private:
    int value;
    
public:
    ClassB(int v) : value(v) {}
    
    // Declare the friend function
    friend void swapValues(ClassA &a, ClassB &b);
    
    void display() const {
        std::cout << "ClassB value: " << value << std::endl;
    }
};

// Friend function definition
void swapValues(ClassA &a, ClassB &b) {
    int temp = a.value;
    a.value = b.value;
    b.value = temp;
}

int main() {
    ClassA objA(10);
    ClassB objB(20);
    
    std::cout << "Before swap:" << std::endl;
    objA.display();
    objB.display();
    
    // Swap values
    swapValues(objA, objB);
    
    std::cout << "After swap:" << std::endl;
    objA.display();
    objB.display();
    
    return 0;
}
