#include<bits/stdc++.h>
using namespace std;
 
#define R 4
#define C 4
 
// this is to print the matrix in a reverse wave form
void WavePrint(int m, int n, int arr[R][C])
{
    int i, j = n - 1, wave = 1;
 
    /* m     - Ending row index
        n     - Ending column index
        i, j     - Iterator
        wave     - for Direction
        wave = 1 - Wave direction down or we can say wave up->down
        wave = 0 - Wave direction up / wave down-> up  */
    while (j >= 0) {
         
        // Check whether to go in
        // upward or downward we can also use & oprator to check
        // if the row no is odd or even to do so
        if (wave == 1) {
             
            // Print the element of the matrix
            // downward since the value of wave = 1 means row value is odd

            for (i = 0; i < m; i++)
                cout << arr[i][j] << " "; 
           
            wave = 0;
            j--;
        }
        else {
             
            // Print the elements of the
            // matrix upward since the value
            // of wave = 0 means row value is even
            // so we'll run reverse loop from rowNo - 1 to row 0
            for (i = m - 1; i >= 0; i--)
                cout << arr[i][j] << " ";
             
            wave = 1;
            j--;
        }
    }
}
 
int main()
{
    int arr[R][C] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };                   
    
    WavePrint(R, C, arr);
     
    return 0;
}