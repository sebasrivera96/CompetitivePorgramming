/*
A boolean matrix has the parity property when each row and each column has an 
even sum, i.e. contains an even number of bits which are set. 
Here's a 4 x 4 matrix which has the parity property:

1 0 1 0

0 0 0 0

1 1 1 1

0 1 0 1


The sums of the rows are 2, 0, 4 and 2. The sums of the columns are 2, 2, 2 and 2.
Your job is to write a program that reads in a matrix and checks if it has the 
parity property. If not, your program should check if the parity property can be 
established by changing only one bit. If this is not possible either, the matrix 
should be classified as corrupt. 

*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    int totalOfColumns[100];

    do{
        cin >> N;
        // Initialize for each test case
        memset(totalOfColumns, 0, sizeof(totalOfColumns));

        if(N > 0){
            int tN = 0;
            int errorsRow = 0;
            int errorsCol = 0;
            int indexErrorCol = -1;
            int indexErrorRow = -1;
            
            // This while will ensure the reading of all the rows
            while(tN++ < N){
                // The row can be computed as currentRow = N - tN
                int totalOfRow = 0;

                for(int iCol = 0; iCol < N; iCol++){
                    int tempBit;
                    cin >> tempBit;

                    totalOfColumns[iCol] += tempBit;
                    totalOfRow += tempBit;
                }
                // Check for error in totalRow
                if(totalOfRow % 2 != 0){
                    errorsRow ++;
                    indexErrorRow = tN;    
                }
            }

            // Look for errors in the columns
            for(int i = 0; i < N; i++){
                // cout << totalOfColumns[i] << "\t";
                if(totalOfColumns[i] % 2 != 0){
                    errorsCol++;
                    indexErrorCol = i;
                }
            }
            // CASE with no errors at all
            if(indexErrorCol == -1 && indexErrorRow == -1){
                cout << "OK" << endl;
            }
            // If just one error in either columns or rows
            else if((indexErrorCol == -1 && indexErrorRow != -1) || (indexErrorCol != -1 && indexErrorRow == -1) || errorsCol > 1 || errorsRow > 1){
                cout << "Corrupt" << endl;
            }
            // If one error error in cols and one error in rows 
            else if(errorsRow == 1 && errorsCol == 1){
                indexErrorCol++;
                cout << "Change bit (" << (indexErrorRow) << ',' << (indexErrorCol) << ")" << endl;
            }
        }
    }while(N > 0);
    return 0;
}
