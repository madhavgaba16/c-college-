// #include<iostream>
// #include<vector>
// #include<iomanip>
// using namespace std;
// void printtable(vector<int>&available,vector<vector<int>>&need,vector<vector<int>>&allocation,int processes, int resources,vector<int>&max){
//     cout<<left<<setw(10)<<"processes"<<setw(20)<<"allocation"<<setw(20)<<"max"<<setw(20)<<"need"<<"avalable\n";
//     for (int i = 0; i < processes; ++i) {
//         cout << left << "P" << i << setw(8);
//             for (int j = 0; j < resources; ++j) {
//             cout << allocation[i][j] << " ";
//         }
        
//         cout<<setw(12);
//          for (int j = 0; j <resources; ++j) {
//             cout << max[i][j] << " ";
//         }
//         cout<<setw(12);
//          for (int j = 0; j <resources; ++j) {
//             cout << need[i][j] << " ";
//         }
//         cout<<setw(12);
//         if(i==0){   
//         for (int j = 0; j <resources; ++j) {
//             cout << available[j] << " ";
//         }
//         }
//         cout<<endl;

//     }
//     cout<<endl;

// }
// bool banker(vector<vector<int>>&allocation,vector<vector<int>>&need,vector<int>&available,int processes,int resources,vector<vector<int>>max){
//     vector<bool>finished(processes,false);
//     vector<int>work= available;
//     vector<int>safesequen;
//     printtable(available,need,allocation,processes,resources,max);
//     for(int i =0 ;i<processes;i++){
//         bool found =false;
//         for(int p = 0;p<processes;p++){
//                 if(!finished[p]){
//                     bool canallocate = true ;
//                     for(int k = 0 ;k<resources;k++){
//                         if(need[p][k]>work[k]){
//                             canallocate= false;
//                             break;
//                         }
//                     }
//                     if(canallocate){
//                         for(int k = 0 ;k<resources;k++){
//                           work[k]+=allocation[p][k];
//                           allocation[p][k]=max[p][k];
//                           need[p][k]=0;
//                     }
//                     finished[p]= true; 
//                 found=true;
//                 safesequen.push_back(p);
//                  printtable(work,need,allocation,processes,resources,max);
//                  break;
//                     }

//                 }
//         }
//         if(!found){
//             cout<<"safe sequence dosn't exist"<<endl;
//             return false;   
//         }
//     }
//    cout<<"safe sequence does exist ";
//    for(int p:safesequen){
//     cout<<"P"+p+" ";

//    }
//    cout<<endl;
//    return true;

// }
// int main()
// {
//     int processes;
//     int resources;
//     cout<<"enter the number of the processes"<<endl;
//     cin>>processes;
//     cout<<"enter the number of the resourcese"<<endl;
//     cin>>resources;
//     vector<int>available(resources);
//     vector<vector<int>>max(processes,vector<int>(resources));
//     vector<vector<int>>need(processes,vector<int>(resources));
//      vector<vector<int>>allocation(processes,vector<int>(resources));
//         cout<<"enter the available resource"<<endl;
//     for(int i =0 ;i<resources;i++){
//         cin>>available[i];
//     }
//     cout<<"enter the maximun resources"<<endl;
//     for(int i =0 ;i<processes;i++){
//         for(int j =0 ;resources;j++){
//             cin>>max[i][j];
//         }
//     }
//     cout<<"enter the allocation resources"<<endl;
//     for(int i =0 ;i<processes;i++){
//         for(int j =0 ;j<resources;j++){
//             cin>>allocation[i][j];
//         }
//     }
//     //calculate the need matrix;
//     for(int i =0 ;i<processes;i++){
//         for(int j =0 ;j<resources;j++){
//            need[i][j]= max[i][j]-allocation[i][j];
//         }
//     }
//     banker(allocation,need,available,processes,resources,max);

    

//  return 0;
// }
// #include <iostream>
// #include <vector>
// #include <iomanip>
// using namespace std;

// void printtable(vector<int> &available, vector<vector<int>> &need, vector<vector<int>> &allocation, int processes, int resources, vector<vector<int>> &max) {
//     cout << left << setw(10) << "Processes" << setw(20) << "Allocation" << setw(20) << "Max" << setw(20) << "Need" << "Available\n";
//     for (int i = 0; i < processes; ++i) {
//         cout << left << "P" << i << setw(8);
//         for (int j = 0; j < resources; ++j) {
//             cout << allocation[i][j] << " ";
//         }

//         cout << setw(12);
//         for (int j = 0; j < resources; ++j) {
//             cout << max[i][j] << " ";
//         }

//         cout << setw(12);
//         for (int j = 0; j < resources; ++j) {
//             cout << need[i][j] << " ";
//         }

//         cout << setw(12);
//         if (i == 0) {
//          cout<<setw(12);
//             for (int j = 0; j < resources; ++j) {
//                 cout << available[j] << " ";
//             }
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

// bool banker(vector<vector<int>> &allocation, vector<vector<int>> &need, vector<int> &available, int processes, int resources, vector<vector<int>> &max) {
//     vector<bool> finished(processes, false);
//     vector<int> work = available;
//     vector<int> safesequen;

//     printtable(available, need, allocation, processes, resources, max);

//     for (int i = 0; i < processes; i++) {
//         bool found = false;
//         for (int p = 0; p < processes; p++) {
//             if (!finished[p]) {
//                 bool canallocate = true;
//                 for (int k = 0; k < resources; k++) {
//                     if (need[p][k] > work[k]) {
//                         canallocate = false;
//                         break;
//                     }
//                 }
//                 if (canallocate) {
//                     for (int k = 0; k < resources; k++) {
//                         work[k] += allocation[p][k];
//                         allocation[p][k] = max[p][k];
//                         need[p][k] = 0;
//                     }
//                     finished[p] = true;
//                     found = true;
//                     safesequen.push_back(p);
//                     printtable(work, need, allocation, processes, resources, max);
//                     break;
//                 }
//             }
//         }
//         if (!found) {
//             cout << "Safe sequence doesn't exist" << endl;
//             return false;
//         }
//     }

//     cout << "Safe sequence does exist: ";
//     for (int p : safesequen) {
//         cout << "P" << p << " ";
//     }
//     cout << endl;
//     return true;
// }

// int main() {
//     int processes;
//     int resources;
//     cout << "Enter the number of processes: ";
//     cin >> processes;
//     cout << "Enter the number of resources: ";
//     cin >> resources;

//     vector<int> available(resources);
//     vector<vector<int>> max(processes, vector<int>(resources));
//     vector<vector<int>> need(processes, vector<int>(resources));
//     vector<vector<int>> allocation(processes, vector<int>(resources));

//     cout << "Enter the available resources:\n";
//     for (int i = 0; i < resources; i++) {
//         cin >> available[i];
//     }

//     cout << "Enter the maximum resources matrix:\n";
//     for (int i = 0; i < processes; i++) {
//         for (int j = 0; j < resources; j++) { // Fixed incorrect loop bound.
//             cin >> max[i][j];
//         }
//     }

//     cout << "Enter the allocation matrix:\n";
//     for (int i = 0; i < processes; i++) {
//         for (int j = 0; j < resources; j++) { // Fixed incorrect loop bound.
//             cin >> allocation[i][j];
//         }
//     }

//     // Calculate the need matrix.
//     for (int i = 0; i < processes; i++) {
//         for (int j = 0; j < resources; j++) {
//             need[i][j] = max[i][j] - allocation[i][j];
//         }
//     }

//     banker(allocation, need, available, processes, resources, max);

//     return 0;
// }
// #include <iostream>
// #include <vector>
// #include <iomanip>
// using namespace std;

// void printtable(vector<int>& available, vector<vector<int>>& need, vector<vector<int>>& allocation, int processes, int resources, vector<vector<int>>& max) {
//     cout << left << setw(10) << "Processes" << setw(20) << "Allocation" << setw(20) << "Max" << setw(20) << "Need" << "Available\n";
//     for (int i = 0; i < processes; ++i) {
//         cout << left << "P" << i << setw(8);
//         for (int j = 0; j < resources; ++j) {
//             cout << allocation[i][j] << " ";
//         }

//         cout << setw(12);
//         for (int j = 0; j < resources; ++j) {
//             cout << max[i][j] << " ";
//         }

//         cout << setw(12);
//         for (int j = 0; j < resources; ++j) {
//             cout << need[i][j] << " ";
//         }

//         cout << setw(12);
//         if (i == 0) {
//             for (int j = 0; j < resources; ++j) {
//                 cout << available[j] << " ";
//             }
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

// bool banker(vector<vector<int>>& allocation, vector<vector<int>>& need, vector<int>& available, int processes, int resources, vector<vector<int>>& max) {
//     vector<bool> finished(processes, false);
//     vector<int> work = available;
//     vector<int> safesequen;

//     printtable(available, need, allocation, processes, resources, max);

//     for (int i = 0; i < processes; i++) {
//         bool found = false;
//         for (int p = 0; p < processes; p++) {
//             if (!finished[p]) {
//                 bool canAllocate = true;
//                 for (int k = 0; k < resources; k++) {
//                     if (need[p][k] > work[k]) {
//                         canAllocate = false;
//                         break;
//                     }
//                 }
//                 if (canAllocate) {
//                     // Allocate resources to the process
//                     for (int k = 0; k < resources; k++) {
//                         work[k] += allocation[p][k];
//                     }
//                     finished[p] = true;
//                     found = true;
//                     safesequen.push_back(p);

//                     // After allocating resources, print the table
//                     cout << "After allocating to P" << p << ":\n";
//                     printtable(work, need, allocation, processes, resources, max);
//                     break;
//                 }
//             }
//         }

//         if (!found) {
//             cout << "Safe sequence doesn't exist.\n";
//             return false;   
//         }
//     }

//     cout << "Safe sequence does exist: ";
//     for (int p : safesequen) {
//         cout << "P" << p << " ";
//     }
//     cout << endl;
//     return true;
// }

// int main() {
//     int processes;
//     int resources;
//     cout << "Enter the number of processes: ";
//     cin >> processes;
//     cout << "Enter the number of resources: ";
//     cin >> resources;

//     vector<int> available(resources);
//     vector<vector<int>> max(processes, vector<int>(resources));
//     vector<vector<int>> need(processes, vector<int>(resources));
//     vector<vector<int>> allocation(processes, vector<int>(resources));

//     cout << "Enter the available resources:\n";
//     for (int i = 0; i < resources; i++) {
//         cin >> available[i];
//     }

//     cout << "Enter the maximum resources matrix:\n";
//     for (int i = 0; i < processes; i++) {
//         for (int j = 0; j < resources; j++) {
//             cin >> max[i][j];
//         }
//     }

//     cout << "Enter the allocation matrix:\n";
//     for (int i = 0; i < processes; i++) {
//         for (int j = 0; j < resources; j++) {
//             cin >> allocation[i][j];
//         }
//     }

//     // Calculate the need matrix.
//     for (int i = 0; i < processes; i++) {
//         for (int j = 0; j < resources; j++) {
//             need[i][j] = max[i][j] - allocation[i][j];
//         }
//     }

//     banker(allocation, need, available, processes, resources, max);

//     return 0;
// }
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Function to print the tables with fixed-width columns
void printtable(vector<int>& available, vector<vector<int>>& need, vector<vector<int>>& allocation, int processes, int resources, vector<vector<int>>& max) {
    // Set a column width to ensure proper alignment
    const int width = 10;  // You can adjust this width based on your needs

    cout << left << setw(width) << "Processes";

    // Print the headers for Allocation, Max, Need, and Available with proper spacing
    for (int j = 0; j < resources; ++j) {
        cout << setw(width) << "Allocation " << j;
    }

    for (int j = 0; j < resources; ++j) {
        cout << setw(width) << "Max " << j;
    }

    for (int j = 0; j < resources; ++j) {
        cout << setw(width) << "Need " << j;
    }

    cout << setw(width) << "Available" << endl;

    // Print the rows for each process
    for (int i = 0; i < processes; ++i) {
        cout << left << setw(width) << i; // Process ID

        // Print allocation values
        for (int j = 0; j < resources; ++j) {
            cout << setw(width) << allocation[i][j];
        }

        // Print max values
        for (int j = 0; j < resources; ++j) {
            cout << setw(width) << max[i][j];
        }

        // Print need values
        for (int j = 0; j < resources; ++j) {
            cout << setw(width) << need[i][j];
        }

        // Print available resources for the first process only
        if (i == 0) {
            cout << setw(width);
            for (int j = 0; j < resources; ++j) {
                cout << setw(width) << available[j];
            }
        }

        cout << endl;
    }
    cout << endl;
}

// Function implementing Banker's Algorithm to check for safe sequence
bool banker(vector<vector<int>>& allocation, vector<vector<int>>& need, vector<int>& available, int processes, int resources, vector<vector<int>>& max) {
    vector<bool> finished(processes, false);
    vector<int> work = available;
    vector<int> safesequence;

    // Print initial state
    printtable(available, need, allocation, processes, resources, max);

    for (int i = 0; i < processes; i++) {
        bool found = false;
        for (int p = 0; p < processes; p++) {
            if (!finished[p]) {
                bool canallocate = true;
                // Check if all needs can be satisfied with the available resources
                for (int k = 0; k < resources; k++) {
                    if (need[p][k] > work[k]) {
                        canallocate = false;
                        break;
                    }
                }
                if (canallocate) {
                    // Allocate resources and mark process as finished
                    for (int k = 0; k < resources; k++) {
                        work[k] += allocation[p][k];  // Release allocated resources
                    }
                    finished[p] = true;
                    safesequence.push_back(p);  // Add process to safe sequence
                    cout << "After allocating to P" << p << ":\n";
                    printtable(work, need, allocation, processes, resources, max);
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            cout << "Safe sequence doesn't exist" << endl;
            return false;   // If no process can be allocated, no safe sequence exists
        }
    }

    // If all processes finished, print the safe sequence
    cout << "Safe sequence exists: ";
    for (int p : safesequence) {
        cout << "P" << p << " ";
    }
    cout << endl;

    return true;
}

int main() {
    int processes;
    int resources;
    cout << "Enter the number of processes: ";
    cin >> processes;
    cout << "Enter the number of resources: ";
    cin >> resources;

    vector<int> available(resources);
    vector<vector<int>> max(processes, vector<int>(resources));
    vector<vector<int>> need(processes, vector<int>(resources));
    vector<vector<int>> allocation(processes, vector<int>(resources));

    cout << "Enter the available resources:\n";
    for (int i = 0; i < resources; i++) {
        cin >> available[i];
    }

    cout << "Enter the maximum resources matrix:\n";
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            cin >> max[i][j];
        }
    }

    cout << "Enter the allocation matrix:\n";
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            cin >> allocation[i][j];
        }
    }

    // Calculate the need matrix
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Call the Banker's Algorithm
    banker(allocation, need, available, processes, resources, max);

    return 0;
}
