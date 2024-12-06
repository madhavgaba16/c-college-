#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int vertex,edge;
    cin>>vertex>>edge;
    vector<vector<bool>>Adjmat(vertex,vector<bool>(vertex,0));
    int u ,v;
    for(int i =0 ;i<vertex;i++){
        cin>>u>>v;
        Adjmat[u][v]=1;
         Adjmat[v][u]=1;
    }
 return 0;
}