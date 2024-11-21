    // #include<iostream>
    // #include<algorithm>
    // #include<vector>
    // #include<iomanip>
    // class process{
    //     public:
    //     int pid;
    //     int arrivaltime;
    //     int bursttime;
    //     int remainingtime;
    //     int througaroundtime;
    //     int waitingtime;
    //     int completetime;
    //     process(int id , int arrival,int burst):pid(id), arrivaltime(arrival),bursttime(burst)
    //             ,remainingtime(burst),througaroundtime(0),waitingtime(0),completetime(0){}

    // };
    // void displayghattable(vector<int>ghattable,vector<int>ghattimes){
    //     cout << "\nGantt Chart:\n";
    //     for (int pid : ghattable) {
    //         if (pid == -1)
    //             cout << "| IDLE ";
    //         else
    //             cout << "| P" << pid << " ";
    //     }
    //     cout << "|\n";

    //     for (int time :ghattimes) {
    //         cout << time << "\t";
    //     }
    //     cout << "\n";
    // }
    // void displayresult(vector<process>processes){
    // int totalWaitingTime =0 ;
    //     cout << "\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
    //     for (process & p : processes) {
    //         cout << "P" << p.pid << "\t" << p.arrivaltime << "\t" << p.bursttime<< "\t"
    //             << p.completetime << "\t\t" << p.througaround<< "\t\t" << p.    << "\n";
    //         totalWaitingTime += p.waitingTime;
    //     }

    //     cout << "\nAverage Waiting Time: " << fixed << setprecision(2)
    //         << (totalWaitingTime / processes.size()) << "\n";
    // }
    // void fcfs(vector<process>& processes){
    //         int currentime =0 ;
    // vector<int>ghattable,ghattimes;
    //         for(process &p : processes){
    //         currentime= max(currentime,p.arrivaltime);
    //         ghattable.push_back(p.pid);
    //         ghattimes.push_back(currentime);
    //         p.completetime= currentime+p.bursttime;
    //         p.througaroundtime= p.completetime-p.arrivaltime;
    //         p.waitingtime =p.througaroundtime-p.arrivaltime;
    //         currentime+=p.bursttime;
    //         }
    //         ghattimes.push_back(currentime);
    //         displayghattable(ghattable , ghattimes);
    //     displayresult(processes);


    // };
    // int main(){
    //     int n;
    //     cout << "Enter the number of processes: ";
    //     cin >> n;

    //     vector<process> processes;
    //     for (int i = 0; i < n; ++i) {
    //         int arrivalTime, burstTime;
    //         cout << "Enter arrival time and burst time for Process P" << i + 1 << ": ";
    //         cin >> arrivalTime >> burstTime;
    //     process p(i + 1, arrivalTime, burstTime);
    //     processes.push_back(p);
        
    //     }
    //     sort(processes.begin(), processes.end(),[](const process&a,const process&b){
    //         return a.arrivaltime<b.arrivaltime;
            
    //     });
    //     fcfs(processes);
    // return 0 ;
    // }
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

class process {
public:
    int pid;                // Process ID
    int arrivaltime;        // Arrival Time
    int bursttime;          // Burst Time
    int remainingtime;      // Remaining Time
    int througaroundtime;   // Turnaround Time
    int waitingtime;        // Waiting Time
    int completetime;       // Completion Time

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
            cout << "| P" << pid << " ";
    }
    cout << "|\n";

    for (int time : ghattimes) {
        cout << time << "\t";
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

// First-Come-First-Serve (FCFS) scheduling algorithm
void fcfs(vector<process>& processes) {
    int currentime = 0;
    vector<int> ghattable, ghattimes;

    for (process& p : processes) {
        currentime = max(currentime, p.arrivaltime); // Handle idle time if currentime < arrivaltime
        ghattable.push_back(p.pid);
        ghattimes.push_back(currentime);

        p.completetime = currentime + p.bursttime;                 // Calculate completion time
        p.througaroundtime = p.completetime - p.arrivaltime;       // Calculate turnaround time
        p.waitingtime = p.througaroundtime - p.bursttime;          // Calculate waiting time

        currentime += p.bursttime; // Update current time
    }

    ghattimes.push_back(currentime); // Add the final time to Gantt chart
    displayghattable(ghattable, ghattimes);
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

    fcfs(processes); // Call FCFS scheduling
    return 0;
}
