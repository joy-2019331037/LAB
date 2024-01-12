//yt channel apnaCollege
#include <bits/stdc++.h>
using namespace std;

//learn how to pass a pointer to a pointer (for passing 2d arrays in function)

bool isSafe(int** arr, int x, int y, int n){
    int row,col;
    //checking for the current column
    for(int row=0;row<x;row++){
        if(arr[row][y]==1)
            return false;
    }

    //now checking for the left diagonal
    row = x;
    col = y;
    while(row>=0 && col >=0){
        if(arr[row][col]==1)
            return false;
        row--;
        col--;
    }

    //now checking for the right diagonal
    row = x;
    col = y;
    while(row>=0 && col <n){
        if(arr[row][col]==1)
            return false;
        row--;
        col++;
    }

    //if no false statement returned, that means we have a safe place which is v[x][y]
    return true;
}

bool NQueens(int** arr, int x, int n){
    if(x>=n)
        return true;
    for(int col=0;col<n;col++){
        if(isSafe(arr, x, col, n)){
            arr[x][col]=1;

            //now checking if in the following steps we can put our remaining queens or not
            if(NQueens(arr, x+1,n))
                return true;

            //if this doesn't return true, this means that at some point we have failed
            // to put a queen, so now we need to backtrack

            arr[x][col]=0;
            //we don't put the queen here and continue the process of backtracking
        }
    }
    return false; // this means that we have failed to put a queen in any of the n columns
}

int main(){
    int n;
    cout << "Enter Number of Queens : ";
    cin >> n;

    //initializing the array
    int** arr= new int*[n]; //learn dynamic declaration of 2D array
    for(int i=0;i<n;i++){
            arr[i] = new int[n];
        for(int j=0;j<n;j++)
            arr[i][j]=0;
    }

    if(NQueens(arr,0,n)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    }
    else
        cout << "Putting " << n << " queens in a " << n << " * " << n << " grid is not possible\n";
        return 0;
}



/*
Passing a pointer to a pointer

    void processArr(int **a) {
       // Do Something
    }
    // When calling:
    int **array;
    array = new int *[10];
    for(int i = 0; i <10; i++)
       array[i] = new int[10];
    processArr(array);
*/

/*
Dynamic declaration of 2D array

    int** a = new int*[rowCount];
    for(int i = 0; i < rowCount; ++i)
        a[i] = new int[colCount];
*/
