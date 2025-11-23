// Rat in a Maze
// Backtracking strategy: Move forward/down, mark path; backtrack if blocked or dead-end, unmark and
// try alternate route. Task: A maze is given as a binary n x n matrix where 1s are open paths and
// 0s are blocked walls. A rat starts at (0, 0) and must reach (n-1, n-1). The rat can only move
// forward and down. Find and print one valid path from the start to the end.

#include <iostream>
#include <vector>

using namespace std;

bool isSafe(const vector<vector<int>>& maze, int x, int y, int n)
{
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1);
}

bool solveMazeUtil(const vector<vector<int>>& maze, int x, int y, vector<vector<int>>& sol, int n)
{
    if (x == n - 1 && y == n - 1)
    {
        sol[x][y] = 1;
        return true;
    }
    if (isSafe(maze, x, y, n))
    {
        sol[x][y] = 1;
        // Move forward (right)
        if (solveMazeUtil(maze, x, y + 1, sol, n))
            return true;
        // Move down
        if (solveMazeUtil(maze, x + 1, y, sol, n))
            return true;
        sol[x][y] = 0;  // backtrack
    }
    return false;
}

bool solveMaze(const vector<vector<int>>& maze)
{
    int n = maze.size();
    vector<vector<int>> sol(n, vector<int>(n, 0));
    if (solveMazeUtil(maze, 0, 0, sol, n))
    {
        cout << "Path found:\n";
        for (const auto& row : sol)
        {
            for (int val : row) cout << val << ' ';
            cout << '\n';
        }
        return true;
    }
    cout << "No path exists\n";
    return false;
}

int main()
{
    vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {0, 1, 0, 0}, {1, 1, 1, 1}};
    solveMaze(maze);
    return 0;
}

/*
Time Complexity: O(2^(n^2)) — at each cell, we can move in up to 2 directions (worst case).
Space Complexity: O(n^2) — solution matrix and recursion depth.
*/
