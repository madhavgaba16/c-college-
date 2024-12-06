#include <iostream>
#include <vector>
using namespace std;
class process {
public:
    int pid;                
    int arrivaltime;       
    int bursttime;          
    int remainingtime;    
    int througaroundtime;   
    int waitingtime;        
    int completetime;       
    process(int id, int arrival, int burst)
        : pid(id), arrivaltime(arrival), bursttime(burst),
          remainingtime(burst), througaroundtime(0), waitingtime(0), completetime(0) {}
};
void displaythrougharoundtime(vector<process>processes){

for(int i =0 ;i<processes.size();i++){
    cout<<"P"<<i+1<<"througharound time :"<<processes[i].througaroundtime<<endl;
}
}
void displaywaitingtime(vector<process>processes){
for(int i =0 ;i<processes.size();i++){
    cout<<"P"<<i+1<<"waiting time :"<<processes[i].waitingtime<<endl;
}
}
void srjf(vector<process>&processes){
    int currenttime=0 ;
    int n = processes.size();
    
    int complete =0 ;
    int inx =-1;

    while(complete<n){
        int minremtime =100000 ;
        
        for(int i =0 ;i<n;i++){
            if(processes[i].arrivaltime<=currenttime&&processes[i].remainingtime!=0&& processes[i].remainingtime<minremtime){
                minremtime= processes[i].remainingtime;
                  inx = i ;
            }
        }
        if(inx !=-1){
            
            --processes[inx].remainingtime;
            ++currenttime;
            if(processes[inx].remainingtime==0){
                 processes[inx].completetime= currenttime;
        processes[inx].througaroundtime= processes[inx].completetime-processes[inx].arrivaltime;
        processes[inx].waitingtime= processes[inx].througaroundtime-processes[inx].bursttime;
            ++complete;
            }
        }
        else{
            currenttime++;
        }
    }
    displaythrougharoundtime(processes);
    displaywaitingtime(processes);

}
int main(){
 vector<process>processes;
 int processesarrivaltime[]={0,0,0,0,0};
 int processesbursttime[]={2,1,8,4,5};
  for(int i =0 ;i<5;i++){
    process p(i + 1, processesarrivaltime[i], processesbursttime[i]); 
        processes.push_back(p); 
  }
  srjf(processes);
  return 0 ;


}