#include <iostream> 
using namespace std; 
 
int main() { 
    try { 
        cout << "Outer try block" << endl; 
        try { 
            cout << "Inner try block" << endl; 
            throw runtime_error("Inner exception"); 
        } catch (const runtime_error& e) { 
            cout << "Caught in inner block: " << e.what() << endl; 
            throw;  // Re-throw the exception 
        } 
    } catch (const runtime_error& e) { 
        cout << "Caught in outer block: " << e.what() << endl; 
    } 
    return 0; 
}