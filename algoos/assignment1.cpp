#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

class Process {
private:
    int cputime;
 int arrival_time;
int name;
int waiting_time;
int exit_time;
int priority;
public:
    
    Process(int z = 0, int x = 0, int y = 0) : name(z), arrival_time(x), cputime(y), waiting_time(0), exit_time(0) {}
      Process(int z = 0, int x = 0, int y = 0,int k =0 ) : name(z), arrival_time(x), cputime(y), priority(k), waiting_time(0), exit_time(0) {}

    int getArrivalTime() const {

        return arrival_time;
    }
     int getpriority() const {

        return priority();
    }

    int getCPUTime() const {
        return cputime;
    }

    int getName() const {
        return name;
    }

    int getExitTime() const {
        return exit_time;
    }
    void setExitTime(int time) {
        exit_time = time;
    }

    void setWaitingTime(int time) {
        waiting_time = time;
    }
     void setprority(int x) {
        priority = x;
    }
    void setcputime(int x) {
        cputime = x;
    }

    int getWaitingTime() const {
        return waiting_time;
    }
};


bool compareByArrivalTime( Process& a,  Process& b) {
    return a.getArrivalTime() < b.getArrivalTime();
}

class FCFS {
private:
    queue<Process*> q;  
    int curr_time = 0;

public:
  
    void run_FCFS(Process* processes, int size) {
       
        sort(processes, processes + size, compareByArrivalTime);

        for (int i = 0; i < size; i++) {
            q.push(&processes[i]);
        }
        while (!q.empty()) {
            Process* temp = q.front();
            q.pop();

            
            curr_time = max(curr_time, temp->getArrivalTime());  
            temp->setWaitingTime(curr_time - temp->getArrivalTime()); 
            temp->setExitTime(curr_time + temp->getCPUTime()); 
            curr_time = temp->getExitTime();  
           
            cout << "Process " << temp->getName() << ": Waiting Time = " 
                 << temp->getWaitingTime() << ", Exit Time = " << temp->getExitTime() << endl;
                 
        }

       
        computeAverageWaitingTime(processes, size);
        
    }

   
    void computeAverageWaitingTime(Process* processes, int size) {
        int total_waiting_time = 0;
        for (int i = 0; i < size; i++) {
            total_waiting_time += processes[i].getWaitingTime();
        }
        cout << "Average Waiting Time: " << (total_waiting_time / size) << endl;
    }
};
class FCFS {
private:
    queue<Process*> q;  
    int curr_time = 0;

public:
  
    void run_FCFS(Process* processes, int size) {
       
        sort(processes, processes + size, compareByArrivalTime);
        
        for (int i = 0; i < size; i++) {
            q.push(&processes[i]);
        }
        while (!q.empty()) {
            Process* temp = q.front();
            q.pop();

            
            curr_time = max(curr_time, temp->getArrivalTime());  
            temp->setWaitingTime(curr_time - temp->getArrivalTime()); 
            temp->setExitTime(curr_time + temp->getCPUTime()); 
            curr_time = temp->getExitTime();  
           
            cout << "Process " << temp->getName() << ": Waiting Time = " 
                 << temp->getWaitingTime() << ", Exit Time = " << temp->getExitTime() << endl;
                 
        }

       
        computeAverageWaitingTime(processes, size);
        
    }

   
    void computeAverageWaitingTime(Process* processes, int size) {
        int total_waiting_time = 0;
        for (int i = 0; i < size; i++) {
            total_waiting_time += processes[i].getWaitingTime();
        }
        cout << "Average Waiting Time: " << (total_waiting_time / size) << endl;
    }
};

class FCFSP {
private:
    queue<Process*> q;  
    int curr_time = 0;
    

public:
  
    void run_FCFSP(Process* processes, int size) {
   
        sort(processes, processes + size, compareByArrivalTime);
           vector<int>status(size);
           for(int i =0 ;i<size;i++){
            status[i]= processes[i].getArrivalTime()+1000*processes[i].getpriority();
           }
        stack<Process*>s;
        for (int i = size-1; i >=0; i--) {
            s.push(&processes[i]);
        }
        while (!s.empty()) {
            Process* temp = s.top();
            s.pop();
            vector<Process*>sortpriority;
            
            curr_time = max(curr_time, temp->getArrivalTime());
            here:
            int runtime =0 ; 
            if(temp->getCPUTime<s.top()->getArrivalTime()){
                runtime = temp->getCPUTime();
            }
            else{
                runtime = s.top()->getArrivalTime();
            }
           cout<<temp->getName<<" "<<curr_time<<" "<<curr_time+runtime; 
           curr_time += runtime;
           temp->setcputime(temp->getCPUTime-runtime);
           if(temp->getCPUTime()==0){


            
             temp->setExitTime(curr_time);
            continue;
           }
           if(s.top()->getpriority>temp->getpriority){
              sortpriority.push_back(s.top());
              s.pop();
              goto here;
           }
           if(s.top()->getpriority>temp->getpriority){
            
           }

           
        }


            
            curr_time = max(curr_time, temp->getArrivalTime());  
            temp->setWaitingTime(curr_time - temp->getArrivalTime()); 
            temp->setExitTime(curr_time + temp->getCPUTime()); 
            curr_time = temp->getExitTime();  
           
            cout << "Process " << temp->getName() << ": Waiting Time = " 
                 << temp->getWaitingTime() << ", Exit Time = " << temp->getExitTime() << endl;

                 computeAverageWaitingTime(processes, size);
                 
        }

       
        

    

   
    void computeAverageWaitingTime(Process* processes, int size) {
        int total_waiting_time = 0;
        for (int i = 0; i < size; i++) {
            total_waiting_time += processes[i].getWaitingTime();
        }
        cout << "Average Waiting Time: " << (total_waiting_time / size) << endl;
    }
};

int main() {
    int size;
    cout << "Enter number process: "<<endl;
          cin >> size;
 Process* processes = new Process[size];

  for (int i = 0; i < size; i++) {
        int name, arrival_time, cputime;
           cout << "Enter    details   for process " << i + 1 << " (name, arrival time, CPU time): ";
        cin >> name >> arrival_time >> cputime;


        processes[i] = Process(name, arrival_time, cputime);
    }

   
    FCFS scheduler;


    scheduler.run_FCFS(processes, size);

    
    delete[] processes;
    return 0;
}

