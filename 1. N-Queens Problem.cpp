// The N-Queens Problem ♛
// Backtracking strategy: Place queens row by row, backtrack when a placement leads to an attack.
// Task: Write a function that solves the N-Queens puzzle. It should take an integer n as input and
// return all distinct solutions for placing n non-attacking queens on an n x n chessboard.

#include <iostream>
#include <vector>

using namespace std;

bool isSafe(const vector<int>& board, int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
        {
            return false;
        }
    }
    return true;
}

void solveNQueens(int n, int row, vector<int>& board, vector<vector<int>>& solutions)
{
    if (row == n)
    {
        solutions.push_back(board);
        return;
    }
    for (int col = 0; col < n; ++col)
    {
        if (isSafe(board, row, col))
        {
            board[row] = col;
            solveNQueens(n, row + 1, board, solutions);
            board[row] = -1;  // backtrack
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> solutions;
    vector<int> board(n, -1);
    solveNQueens(n, 0, board, solutions);
    return solutions;
}

void printSolution(const vector<int>& board)
{
    int n = board.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << (board[i] == j ? "Q " : ". ");
        }
        cout << '\n';
    }
    cout << '\n';
}

int main()
{
    int n = 4;
    auto solutions = nQueens(n);
    cout << "Total solutions for " << n << "-Queens: " << solutions.size() << "\n\n";
    for (const auto& sol : solutions)
    {
        printSolution(sol);
    }
    return 0;
}

/*
Time Complexity: O(n!) — in worst case, we explore n choices for first row, (n-1) for second, etc.
Space Complexity: O(n) — recursion depth and board state storage.
*/
