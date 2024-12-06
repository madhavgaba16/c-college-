// #include<iostream>
// #include<vector>
// using namespace std;
// int main()  without weight;
// {
//     int vertex ,edges;
//         cin>>vertex>>edges;
//     vector<int>AdjMat[vertex];//adjlist
//     int u ,v;
//     for(int i =0 ;i<vertex;i++){
//        cin>>u>>v;
//        AdjMat[u].push_back(v);
//        AdjMat[v].push_back(u);
//     }
//     for(int i =0 ;i<vertex;i++){
//         cout<<i<<" ->";
//         for(int  j =0 ;j<AdjMat[i].size();j++){
//             cout<<AdjMat[i][j]<<" ";
//         }
//          cout<<endl;
//     }
//  return 0;
// }
#include<iostream>
#include<vector>
using namespace std;
int main()  //with weight;
{
    int vertex ,edges;
        cin>>vertex>>edges;
    vector<pair<int,int>>Adjlist[vertex];//adjlist
    int u ,v,weight;
    for(int i =0 ;i<vertex;i++){
       cin>>u>>v>>weight;
       Adjlist[u].push_back(make_pair(v,weight));
       Adjlist[v].push_back(make_pair(u,weight));
    }
    for(int i =0 ;i<vertex;i++){
        cout<<i<<" ->";
        for(int  j =0 ;j<Adjlist[i].size();j++){
            cout<<Adjlist[i][j].first<<" "<<Adjlist[i][j].second;
        }
         cout<<endl;
    }
 return 0;
}