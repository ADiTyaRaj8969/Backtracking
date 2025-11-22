// Sudoku Solver
// Backtracking strategy: Fill cells one by one; if a digit leads to invalid state, backtrack and
// try next digit. Task: Write a function that solves a 9x9 Sudoku puzzle by filling the empty cells
// (represented by 0). The function should take a partially filled grid and modify it in-place to
// the solved state.

#include <iostream>
#include <vector>

using namespace std;

bool isSafe(const vector<vector<int>>& board, int row, int col, int num)
{
    for (int i = 0; i < 9; ++i)
    {
        if (board[row][i] == num || board[i][col] == num)
            return false;
    }
    int startRow = (row / 3) * 3, startCol = (col / 3) * 3;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[startRow + i][startCol + j] == num)
                return false;
        }
    }
    return true;
}

bool solveSudoku(vector<vector<int>>& board)
{
    for (int row = 0; row < 9; ++row)
    {
        for (int col = 0; col < 9; ++col)
        {
            if (board[row][col] == 0)
            {
                for (int num = 1; num <= 9; ++num)
                {
                    if (isSafe(board, row, col, num))
                    {
                        board[row][col] = num;
                        if (solveSudoku(board))
                            return true;
                        board[row][col] = 0;  // backtrack
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printBoard(const vector<vector<int>>& board)
{
    for (const auto& row : board)
    {
        for (int val : row) cout << val << ' ';
        cout << '\n';
    }
}

int main()
{
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0}, {6, 0, 0, 1, 9, 5, 0, 0, 0}, {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3}, {4, 0, 0, 8, 0, 3, 0, 0, 1}, {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0}, {0, 0, 0, 4, 1, 9, 0, 0, 5}, {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    if (solveSudoku(board))
    {
        cout << "Solved Sudoku:\n";
        printBoard(board);
    }
    else
    {
        cout << "No solution exists\n";
    }
    return 0;
}

/*
Time Complexity: O(9^(n*n)) where n=9, worst case tries all possibilities for empty cells.
Space Complexity: O(n*n) — recursion depth proportional to number of empty cells.
*/
