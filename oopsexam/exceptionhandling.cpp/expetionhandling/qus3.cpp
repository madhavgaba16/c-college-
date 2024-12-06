#include <iostream> 
#include <stdexcept> 
using namespace std; 
class Resource { 
public: 
Resource() { cout << "Resource acquired" << endl; } 
~Resource() { cout << "Resource released" << endl; } 
}; 
void process() { 
Resource res; 
throw runtime_error("Processing error"); 
} 
int main() { 
try { 
process(); 
} catch (const runtime_error& e) { 
cout << "Caught exception: " << e.what() << endl; 
} 
return 0; 
} 