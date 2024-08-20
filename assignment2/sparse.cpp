#include<iostream>
using namespace std;

void sparse(int** arr, int numRows, int numCols) {
    int count = 0;
  
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (arr[i][j] != 0) {
                count++;
            }
        }
    }
    
   
    int** arr2 = new int*[count];
    for (int i = 0; i < count; i++) {
        arr2[i] = new int[3];
    }
    
    int i1 = 0;
    
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (arr[i][j] != 0) {
                arr2[i1][0] = i;          
                arr2[i1][1] = j;
                     arr2[i1][2] = arr[i][j];  // Value
                i1++;
            }
        }
    }
    
    
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr2[i][j] << " ";
        }
        cout << "\n";
    }
   
    for (int i = 0; i < count; i++) {
        delete[] arr2[i];
    }
    delete[] arr2;
}

int main() {
    int numRows = 4;
    int numCols = 4;
    

    int** arr = new int*[numRows];
    for (int i = 0; i < numRows; i++) {
        arr[i] = new int[numCols];
    }
    
    int tempArr[4][4] = {
        {0, 0, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 2},
        {1, 0, 0, 1}
    };
    
    
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            arr[i][j] = tempArr[i][j];
        }
    }


    sparse(arr, numRows, numCols);

    
    for (int i = 0; i < numRows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}