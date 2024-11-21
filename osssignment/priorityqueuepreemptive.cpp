#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include<climits>

using namespace std;
class process{
     public:
    int id ; 
    int bursttime;
    int arrivaltime;
    int priority;
    int remainingtime;
    int compeletetime;
    int througharoundtime;
    int waitingtime;
   
   process(int in,int arrival,int burst,int priori):id(in),arrivaltime(arrival),bursttime(burst),priority(priori),remainingtime(burst),waitingtime(0),compeletetime(0),througharoundtime(0){}
};
void averagewaitingtime(vector<process>processes){
    float answer=0 ;
    for(int i =0 ;i<processes.size();i++){
        answer+=processes[i].waitingtime;
    }
    answer = answer/processes.size();
    cout<<"average waiting time :"<<answer<<endl;
}
void printsequence(vector<int>sequence){
    for(int i =0 ;i<sequence.size();i++){
        cout<<"P"<<sequence[i]+1<<" "; 
    }
}

void priorityprem(vector<process>processes){
    int time =0 ;
    int complete =0 ;
    vector<int>sequence;
            while(complete<processes.size()){
                int in= -1;
                int highpriority = INT_MIN;
                for(int i =0;i<processes.size();i++){
                    if(processes[i].arrivaltime<=time&&processes[i].remainingtime!=0&&processes[i].priority>highpriority){
                        in = i ;
                        highpriority= processes[i].priority;
                    }
                }
                if(in!=-1){
                    time++;
                    processes[in].remainingtime--;
                    if(processes[in].remainingtime==0){

                      processes[in].compeletetime=time;
                     processes[in].througharoundtime= processes[in].compeletetime-processes[in].arrivaltime;
                     processes[in].waitingtime = processes[in].througharoundtime-processes[in].bursttime;
                    complete++;
                    
                    }
                    if(sequence.empty() ||sequence.back()!=in)
                     sequence.push_back(in);
                }else{
                    time++;
                }

            }
            printsequence(sequence);
            averagewaitingtime(processes);       
}
int main()
{
    int n ;
    int resource;
    cout<<"number of the process:"<<endl;
    cin>>n;
    
    vector<process>processes;
   for (int i = 0; i < n; ++i) {
        int arrivalTime, burstTime,priority;
        cout << "Enter arrival time and burst time , priority for Process P" << i + 1 << ": ";
        cin >> arrivalTime >> burstTime>>priority;
        process p(i + 1, arrivalTime, burstTime,priority);
        processes.push_back(p) ;
    }

    
    sort(processes.begin(), processes.end(), [](const process& a, const process& b) {
        return a.arrivaltime < b.arrivaltime;
    });
    priorityprem(processes);

 return 0;
}