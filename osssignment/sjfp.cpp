
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
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

    // Constructor for initializing process details
    process(int id, int arrival, int burst)
        : pid(id), arrivaltime(arrival), bursttime(burst),
          remainingtime(burst), througaroundtime(0), waitingtime(0), completetime(0) {}
};

// Function to display the Gantt chart
void displayghattable(vector<int> ghattable, vector<int> ghattimes) {
    cout << "\nGantt Chart:\n";
    for (int pid : ghattable) {
        if (pid == -1) // IDLE case
            cout << "| IDLE ";
        else
            cout << "| P" << pid << "  ";
    }
    cout << "|\n";

    for (int time : ghattimes) {
        cout << time << "  3";
    }
    cout << "\n";
}

// Function to display results of the scheduling
void displayresult(vector<process> processes) {
    int totalWaitingTime = 0;
    cout << "\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for (process& p : processes) {
        cout << "P" << p.pid << "\t" << p.arrivaltime << "\t" << p.bursttime << "\t"
             << p.completetime << "\t\t" << p.througaroundtime << "\t\t" << p.waitingtime << "\n";
        totalWaitingTime += p.waitingtime;
    }

    cout << "\nAverage Waiting Time: " << fixed <<   setprecision(2)
         << (static_cast<double>(totalWaitingTime) / processes.size()) << "\n";
}
void srfp(vector<process>processes){
    int currenttime=0 ;
    int n = processes.size();
    vector<int>ghattable,ghattime;
    int complete =0 ;
    int inx =-1;
    while(complete<n){
        int minremtime =100000 ;
        int currentime  = processes[0].arrivaltime;
        for(int i =0 ;i<n;i++){
            if(processes[i].arrivaltime<=currentime&&processes[i].remainingtime!=0&& processes[i].remainingtime<minremtime){
                minremtime= processes[i].remainingtime;
                  inx = i ;
            }
        }
        if(inx !=-1){
            if(ghattable.empty()||ghattable.back()!=inx){
                ghattable.push_back(inx);
                ghattime.psuh_back(currentime);
            }
            --processes[inx].remainingtime;
            ++currentime;
            if(processes[inx].remainingtime==0){
                
            }
        }

    }
}