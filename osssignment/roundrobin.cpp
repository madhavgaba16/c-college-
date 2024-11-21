    // #include<iostream>
    // #include<vector>
    // #include<queue>
    // #include<algorithm>
    // using namespace std;
    // class process{
    //     public :
    //     int id ;
    //     int arrivaltime;
    //     int bursttime;
    //     int remainingtime;
    //     int completetime;
    //     int waitingtime;
    //     int througharoundtime;
    //     process(int inx,int arrival,int burst):id(inx), arrivaltime(arrival), bursttime(burst),
    //           remainingtime(burst), througharoundtime(0), waitingtime(0), completetime(0) {}
    // };
    // void averagewaitingtime(vector<process>processes){
    //     float answer =0 ;
    //     for(int i =0 ;i<processes.size();i++){
    //         answer+=processes[i].waitingtime;
    //     }
    //     cout<<answer/processes.size();
    // }
    // void printsequence(vector<int>sequence){
    //     int i =0;
    //     for(i;i<sequence.size();i++){
    //         cout<<sequence[i]<<" ";
    //     }

    // }
    //  void roundrobin(vector<process>&processes,int quantum){
    //     int time =0 ;
    //     int complete=0 ;
    //     vector<int>sequence;
    //     queue<int>q;
    //     for(int i =0 ;i<processes.size();i++){
    //         q.push(i); 
    //     }
    //  while(complete!=processes.size()){
    //     int index = q.front();
    //     q.pop();
    //     if(processes[index].remainingtime>quantum){
    //         time+=quantum;
    //         processes[index].remainingtime-=quantum;
    //         q.push(index);
    //     }else{
    //         time+=processes[index].remainingtime;
    //         processes[index].remainingtime=0;
    //         processes[index].completetime= time;
    //         processes[index].througharoundtime= processes[index].completetime-processes[index].arrivaltime;
    //         processes[index].waitingtime= processes[index].througharoundtime-processes[index].bursttime;
    //         complete++;
    //     }
    //     sequence.push_back(index);

    //  }
    //  printsequence(sequence);
    //  averagewaitingtime(processes);

    //  }
    // int main()
    // {
    //     int n;
    //     cout << "Enter the number of processes: ";
    //     cin >> n;
    //     int quantum;
    //      cout << "Enter the time quantum: ";
    //     cin >> quantum;

    //     vector<process> processes;
    //     for (int i = 0; i < n; ++i) {
    //         int arrivalTime, burstTime;
    //         cout << "Enter arrival time and burst time for Process P" << i + 1 << ": ";
    //         cin >> arrivalTime >> burstTime;
    //         process p(i + 1, arrivalTime, burstTime);
    //         processes.push_back(p);                  
    //     }
    //     sort(processes.begin(), processes.end(), [](const process& a, const process& b) {
    //         return a.arrivaltime < b.arrivaltime;
    //     });
    //     roundrobin(processes,quantum);
        
    //  return 0;
    // }
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


class process {
public:
    int id;                 
    int arrivaltime;         
    int bursttime;           
    int remainingtime;       
    int waitingtime;         
    int turnaroundtime;      

    
    process(int idx, int arrival, int burst)
        : id(idx), arrivaltime(arrival), bursttime(burst),
          remainingtime(burst), turnaroundtime(0), waitingtime(0), completetime(0) {}
};


void averagewaitingtime(const vector<process>& processes) {
    float totalWaitingTime = 0;
    for (const auto& p : processes) {
        totalWaitingTime += p.waitingtime;
    }
    cout << "\nAverage Waiting Time: " << totalWaitingTime / processes.size() << endl;
}


void printsequence(const vector<int>& sequence) {
    cout << "Execution Sequence: ";
    for (int id : sequence) {
        cout << "P" << id << " ";
    }
    cout << endl;
}


void roundrobin(vector<process>& processes, int quantum) {
    int time = 0;      
    int complete = 0; 
    vector<int> sequence;
    queue<int> q;

   
    for (int i = 0; i < processes.size(); i++) {
        if (processes[i].arrivaltime <= time) {
            q.push(i);
        }
    }

   
    while (complete < processes.size()) {
        if (q.empty()) {
           
            time = processes[complete].arrivaltime;
            for (int i = 0; i < processes.size(); i++) {
                if (processes[i].arrivaltime <= time && processes[i].remainingtime > 0) {
                    q.push(i);
                }
            }
            continue;
        }

        int index = q.front();
        q.pop();

       
        if (processes[index].remainingtime > quantum) {
            time += quantum;
            processes[index].remainingtime -= quantum;
        } else {
            time += processes[index].remainingtime;
            processes[index].remainingtime = 0;
            processes[index].completetime = time;
            processes[index].turnaroundtime = processes[index].completetime - processes[index].arrivaltime;
            processes[index].waitingtime = processes[index].turnaroundtime - processes[index].bursttime;
            complete++;
        }

        sequence.push_back(processes[index].id);

       
        for (int i = 0; i < processes.size(); i++) {
            if (processes[i].arrivaltime <= time && processes[i].remainingtime > 0 && 
                find(sequence.begin(), sequence.end(), i) == sequence.end()) {
                q.push(i);
            }
        }
    }

    
    printsequence(sequence);
    averagewaitingtime(processes);
}


int main() {
    int n, quantum;

    
    cout << "Enter the number of processes: ";
    cin >> n;

   
    cout << "Enter the time quantum: ";
    cin >> quantum;

    vector<process> processes;

    
    for (int i = 0; i < n; ++i) {
        int arrivalTime, burstTime;
        cout << "Enter arrival time and burst time for Process P" << i + 1 << ": ";
        cin >> arrivalTime >> burstTime;
        process p(i + 1, arrivalTime, burstTime);
        processes[i]=p ;

    }

    // Sort processes by arrival time
    sort(processes.begin(), processes.end(), [](const process& a, const process& b) {
        return a.arrivaltime < b.arrivaltime;
    });

    // Perform Round Robin Scheduling
    roundrobin(processes, quantum);

    return 0;
}
