#include <iostream>
using namespace std;

int main()
{
    int arr[3][3];
    cout << "Give the array:";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "The matrix is :" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int z = 0, nz = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == 0)
            {
                z++;
            }

            else
                nz++;
        }
    }

    if (nz > z)
    {
        cout << "not a sparse";
    }

    else
    {
        cout << "Sparse"<<endl;

        int s[nz][3];

        int k = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j] != 0)
                {
                    s[k][0] = i;
                    s[k][1] = j;
                    s[k][2] = arr[i][j];
                    k++;
                }
            }
        }

        cout << "The sparse matrix is :"<<endl;
        for (int i = 0; i < nz; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << s[i][j] << " ";
            }
            cout << endl;
        }

        cout<<endl;


        //transpose

        int transpose[nz][3];
        int t_index = 0;

        
        
            for (int j = 0; j < nz; j++)
            {
          
            {
                transpose[t_index][0] = s[j][1];
                transpose[t_index][1] = s[j][0];
                transpose[t_index][2] = s[j][2];
                t_index++;
            }
            }
        

        cout << "The transpose of the sparse matrix is :" << endl;
        for (int i = 0; i < nz; i++)
        {
            for (int j = 0; j < 3; j++)
            {
            cout << transpose[i][j] << " ";
            }
            cout << endl;
        }


        // Addition of two sparse matrices
        int arr2[3][3];
        cout << "Give the second array:";
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
            cin >> arr2[i][j];
            }
        }
        int nz1 =0 ;
        int s2[nz1][3];
        k = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
            if (arr2[i][j] != 0)
            {
                s2[k][0] = i;
                s2[k][1] = j;
                s2[k][2] = arr2[i][j];
                k++;
            }
            }
        }

        int result[nz + nz1][3];
        int r_index = 0, i = 0, j = 0;

        while (i < nz && j < nz1)
        {
            if (s[i][0] < s2[j][0] || (s[i][0] == s2[j][0] && s[i][1] < s2[j][1]))
            {
            result[r_index][0] = s[i][0];
            result[r_index][1] = s[i][1];
            result[r_index][2] = s[i][2];
            i++;
            }
            else if (s2[j][0] < s[i][0] || (s2[j][0] == s[i][0] && s2[j][1] < s[i][1]))
            {
            result[r_index][0] = s2[j][0];
            result[r_index][1] = s2[j][1];
            result[r_index][2] = s2[j][2];
            j++;
            }
            else
            {
            result[r_index][0] = s2[i][0];
            result[r_index][1] = s[i][1];
            result[r_index][2] = s[i][2] + s2[j][2];
            i++;
            j++;
            }

            r_index++;
        }

        while (i < nz)
        {
            result[r_index][0] = s[i][0];
            result[r_index][1] = s[i][1];
            result[r_index][2] = s[i][2];
            i++;
            r_index++;
        }

        while (j < nz)
        {
            result[r_index][0] = s2[j][0];
            result[r_index][1] = s2[j][1];
            result[r_index][2] = s2[j][2];
            j++;
            r_index++;
        }

        cout << "The addition of the two sparse matrices is :" << endl;
        for (int i = 0; i < r_index; i++)
        {
            for (int j = 0; j < 3; j++)
            {
            cout << result[i][j] << " ";
            }
            cout << endl;
        }
        

        // Multiplication of two sparse matrices
        int arr3[3][3] = {0};
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
            for (int k = 0; k < 3; k++)
            {
                arr3[i][j] += arr[i][k] * arr2[k][j];
            }
            }
        }

        int s3[nz][3];
        k = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
            if (arr3[i][j] != 0)
            {
                s3[k][0] = i;
                s3[k][1] = j;
                s3[k][2] = arr3[i][j];
                k++;
            }
            }
        }

        cout << "The multiplication of the two sparse matrices is :" << endl;
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < 3; j++)
            {
            cout << s3[i][j] << " ";
            }
            cout << endl;
        }
    }
}
 for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (sparse1[i][1] == sparse2[j][0]) {  // Check if column in A matches row in B
                int row = sparse1[i][0];
                int col = sparse2[j][1];
                int value = sparse1[i][2] * sparse2[j][2];

                // Check if the result entry already exists at (row, col)
                bool neww = true;
                for (int k = 0; k < count4; k++) {
                    if (sparse4[k][0] == row && sparse4[k][1] == col) {
                        sparse4[k][2] += value;  // Add to existing value
                        neww = false;
                        break;
                    }
                }

                // If not found, add a new entry
                if (neww) {
                    sparse4[count4][0] = row;
                    sparse4[count4][1] = col; 
                    sparse4[count4][2] = value;
                    count4++;
                }
            }
        } 
 }