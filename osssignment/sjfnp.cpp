
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
void srjtnp(vector<process>processes){
    int currenttime=processes[0].arrivaltime;
    int n  = processes.size();
    vector<int>ghattable,ghattime;
    int complete =0;
    while(complete<n){
      int mintime = 1000000;
      int ind=-1;
      for(int i  =0 ;i<n ;i++){
        if(processes[i].arrivaltime<=currenttime&&processes[i].completetime==0&&processes[i].bursttime<mintime){
            ind = i ;
            mintime = processes[i].bursttime;

        }

      }
      if(ind!=-1){
        ghattable.push_back(ind+1);
        ghattime.push_back(currenttime);
        currenttime= max(currenttime,processes[ind].arrivaltime)+processes[ind].bursttime;
        processes[ind].completetime= currenttime;
        processes[ind].througaroundtime= currenttime-processes[ind].arrivaltime;
        processes[ind].waitingtime= processes[ind].througaroundtime-processes[ind].bursttime;
            ++complete;
      }
      else{
        if(ghattable.back()!=-1||ghattable.empty()){
        ghattable.push_back(-1);
        ghattime.push_back(currenttime);
        }
        ++currenttime;
      }
      
    }
    ghattime.push_back(currenttime);
      displayghattable(ghattable,ghattime);
      displayresult(processes);
}
int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<process> processes;
    for (int i = 0; i < n; ++i) {
        int arrivalTime, burstTime;
        cout << "Enter arrival time and burst time for Process P" << i + 1 << ": ";
        cin >> arrivalTime >> burstTime;
        process p(i + 1, arrivalTime, burstTime); // Initialize process object
        processes.push_back(p);                  // Add to processes list
    }

    // Sort processes by arrival time
    sort(processes.begin(), processes.end(), [](const process& a, const process& b) {
        return a.arrivaltime < b.arrivaltime;
    });

    srjtnp(processes); // Call FCFS scheduling
    return 0;
}