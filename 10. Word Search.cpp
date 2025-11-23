// Word Search Solver
// Backtracking strategy: For each cell, try all 4 directions; mark visited; backtrack if path
// fails, unmark and try next direction. Task: Given a 2D grid of characters and a word, write a
// function that finds if the word exists in the grid. The word can be constructed from letters in
// sequentially adjacent cells, where "adjacent" cells are those horizontally or vertically
// neighboring. The same letter cell may not be used more than once.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool dfs(vector<vector<char>>& board, const string& word, int idx, int r, int c)
{
    if (idx == static_cast<int>(word.size()))
        return true;
    if (r < 0 || r >= static_cast<int>(board.size()) || c < 0 ||
        c >= static_cast<int>(board[0].size()) || board[r][c] != word[idx])
        return false;

    char temp = board[r][c];
    board[r][c] = '#';  // mark visited

    bool found = dfs(board, word, idx + 1, r + 1, c) || dfs(board, word, idx + 1, r - 1, c) ||
                 dfs(board, word, idx + 1, r, c + 1) || dfs(board, word, idx + 1, r, c - 1);

    board[r][c] = temp;  // backtrack
    return found;
}

bool wordSearch(vector<vector<char>>& board, const string& word)
{
    for (int i = 0; i < static_cast<int>(board.size()); ++i)
    {
        for (int j = 0; j < static_cast<int>(board[0].size()); ++j)
        {
            if (dfs(board, word, 0, i, j))
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    if (wordSearch(board, word))
    {
        cout << "Word '" << word << "' found in grid.\n";
    }
    else
    {
        cout << "Word '" << word << "' not found in grid.\n";
    }
    return 0;
}

/*
Time Complexity: O(m*n*4^L) where m,n are grid dimensions and L is word length (4 directions per
cell). Space Complexity: O(L) — recursion depth equals word length.
*/
