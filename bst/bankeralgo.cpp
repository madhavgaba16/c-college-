#include <iostream>
using namespace std;
int we ;

class Process;  

class Resources {
public:
    int totalResources;  
    int leftResources;      

    Resources(int resource) {
       totalResources= resource;
       leftResources= resource;
    }

    
    void allocateResources(int y, Process* p);
};

class Process {
public:
    int allocatedResources[10]; 
    int maxResources[10];      
    int need[10];             
    bool stillInGame;         
    int resourceTypes;         

    
    Process() {
        for(int i =0 ;i<we;i++){
            demandResources(+)
        }
    }

    
    void demandResources(Resources* r, int x) {
        for (int i = 0; i < resourceTypes; i++) {
            if (allocatedResources[i] + x[i] > maxResources[i]) {
                cout << "Error: Request exceeds maximum required resources for resource type " << i + 1 << endl;
                return;
            }
            if (x[i] <= need[i]) {
                r->allocateResources(x, this);
            }
        }
        check();
    }

 
    void check() {
        bool allResourcesAllocated = true;
        for (int i = 0; i < resourceTypes; i++) {
            if (need[i] > 0) {
                allResourcesAllocated = false;
                break;
            }
        }
        stillInGame = !allResourcesAllocated;
        if (!stillInGame) {
            cout << "Process has all the required resources." << endl;
        }
    }
};


void Resources::allocateResources(int y[], Process* p) {
   
}
void safesequence(Process){

}
int main()
{
    int x ;
    cout<<"enter the total number of the resourcses"<<endl;
    cin<<we;
        
    
 return 0;
}