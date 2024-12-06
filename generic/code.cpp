#include<iostream> 

void increment(int* x) {
    (*x)++; // Increment value pointed by pointer
}

void increment(int& x) {
    x++; // Increment value referenced by reference
}

int main(void) { 
    int a = 5; 
    increment(a); // Call increment by reference
    std::cout << "a: " << a << std::endl; // Print the incremented value of 'a'
    return 0; 
}
