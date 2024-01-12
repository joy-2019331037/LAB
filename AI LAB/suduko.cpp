#include <iostream>
#define N 9
using namespace std;

int step_count=0;

int grid[N][N] = {
    {3, 0, 6, 5, 0, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    {0, 0, 3, 0, 1, 0, 0, 8, 0},
    {9, 0, 0, 8, 6, 3, 0, 0, 5},
    {0, 5, 0, 0, 9, 0, 6, 0, 0},
    {1, 3, 0, 0, 0, 0, 2, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 0, 6, 3, 0, 0},
};
bool isPresentInCol(int col, int num)
{ // check whether num is present in col or not
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}
bool isPresentInRow(int row, int num)
{ // check whether num is present in row or not
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}
bool isPresentInBox(int boxStartRow, int boxStartCol, int num)
{
    // check whether num is present in 3x3 box or not
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow][col + boxStartCol] == num)
                return true;
    return false;
}
// printing grid
void sudokuGrid()
{
   for (int row = 0; row < N; row++)
   {
      for (int col = 0; col < N; col++)
      {
         if (col == 3 || col == 6)
            cout << "| ";
         if (grid[row][col])
            cout << grid[row][col] << " ";
         else
            cout << "_ ";
      }
      if (row == 2 || row == 5)
      {
         cout << endl;
         for (int i = 0; i < N; i++)
            cout << "---";
      }
      cout << endl;
   }
}
pair<int, int> findEmptyPlace()
{ // get empty location and update row and column
    int row, col;
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == 0) // marked with 0 is empty
                return make_pair(row, col);

    return make_pair(-1, -1);
}
bool isValidPlace(int row, int col, int num)
{
    // when item not found in col, row and current 3x3 box
    return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row % 3, col - col % 3, num);
}
bool solveSudoku()
{
    int row, col;
    pair<int, int> p = findEmptyPlace();
    if (p.first == -1)
        return true; // when all places are filled
    row = p.first;
    col = p.second;
    for (int num = 1; num <= 9; num++)
    { // valid numbers are 1 - 9
        if (isValidPlace(row, col, num))
        { // check validation, if yes, put the number in the grid
            grid[row][col] = num;
            if (solveSudoku()) // recursively go for other rooms in the grid
                return true;
            grid[row][col] = 0; // turn to unassigned space when conditions are not satisfied
            step_count++;
        }
    }
    return false;
}

bool isValidInput()
{
    for (int i = 0; i < N; i++)
    {
        bool v[10] = {0};
        for (int j = 0; j < N; j++)
        {
            int val = grid[i][j];
            if (v[val] && val != 0)
            {
                cout << "Invalid Sudoku. Multiple " << val << " in row " << i << endl;
                return false;
            }
            else
                v[val] = true;
        }
    }
    for (int i = 0; i < N; i++)
    {
        bool v[10] = {0};
        for (int j = 0; j < N; j++)
        {
            int val = grid[j][i];
            if (v[val] && val != 0)
            {
                cout << "Invalid Sudoku. Multiple " << val << " in col " << i << endl;
                return false;
            }
            else
                v[val] = true;
        }
    }
    cout << '\n';
    return true;
}

int main()
{  
   cout << "Input Sudoko: "<<endl<<endl;
    sudokuGrid();
    if (!isValidInput())
        return 0;

   cout << "Solution : "<<endl<<endl;
    if (solveSudoku() == true)
        {sudokuGrid();
         cout <<endl<<"Backtracking steps : " << step_count<<endl;
        }
    else
        cout << "No solution exists";
}
