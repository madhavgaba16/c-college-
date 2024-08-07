#include<iostream>
using namespace std;
void tridiognal(int arr [],int length){
    
    int m = (length +2)/3;
    int arr2[m][m];
    int u =0;
for(int  i =0;i<m;i++){
    for(int j =0 ;j<m;j++){
        
        if(i-j<=1 && i-j>=-1){
            arr2[i][j]=arr[u];
            u++;
          
        }
        else
            arr2[i][j]=0;
            
    }
    
}
for(int  i =0 ;i<m;i++){
    for(int j =0 ;j<m;j++){
        cout<<arr2[i][j]<<"  ";
    }
    cout<<"\n";

}

}
int main (){
        int arr[]={1,2,3,4,5,6,7,8,9,10};
        int length = sizeof(arr)/sizeof(arr[0]);
        tridiognal(arr,length);

}