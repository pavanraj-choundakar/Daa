
#include <iostream>
using namespace std;

#define N 4

// Function to print solution
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check whether queen can be placed safely
bool isSafe(int board[N][N], int row, int col)
{
    // Check left side of current row
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
            return false;
    }

    // Check upper diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }

    // Check lower diagonal
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
    {
        if (board[i][j])
            return false;
    }

    return true;
}

// Recursive function to solve N-Queens
bool solveNQUtil(int board[N][N], int col)
{
    // If all queens are placed
    if (col >= N)
        return true;

    // Try placing queen in each row
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;

            if (solveNQUtil(board, col + 1))
                return true;

            // Backtracking
            board[i][col] = 0;
        }
    }

    return false;
}

// Main function
int main()
{
    int board[N][N] = {0};

    if (solveNQUtil(board, 0))
    {
        cout << "N-Queens Solution:" << endl;
        printSolution(board);
    }
    else
    {
        cout << "Solution does not exist" << endl;
    }

    return 0;
}


Run-
  g++ nqueens.cpp -o nqueens
.\nqueens.exe



  output-
  anika_halate@sanu:/mnt/d/DAA$ g++ nqueens.cpp -o nqueens 
anika_halate@sanu:/mnt/d/DAA$ ./nqueens 
N-Queens Solution: 
0 0 1 0  
1 0 0 0  
0 0 0 1  
0 1 0 0
