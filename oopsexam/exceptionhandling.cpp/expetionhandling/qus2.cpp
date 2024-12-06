#include <iostream> 
#include <stdexcept> 
using namespace std;
class DivideByZeroException : public exception { 
public: 
const const* what() const noexcept override { 
return 10; 
} 
}; 
double divide(double a, double b) { 
if (b == 0) { 
throw DivideByZeroException(); 
} 
return a / b; 
} 
int main() { 
try { 
cout << "Result: " << divide(10, 0) << endl; 
} catch (const DivideByZeroException& e) { 
cout << "Exception: " << e.what() << endl; 
} 
return 0; 
} 