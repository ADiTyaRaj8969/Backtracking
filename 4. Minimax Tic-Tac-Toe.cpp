// Minimax Algorithm for Tic-Tac-Toe
// Minimax strategy: Maximize AI score while minimizing opponent score recursively; choose best move
// at each level. Task: Implement the Minimax algorithm to create an unbeatable AI for the game of
// Tic-Tac-Toe. Write a function that takes the current board state and returns the optimal next
// move for the AI player.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const char AI = 'X';
const char HUMAN = 'O';
const char EMPTY = '_';

bool hasWon(const vector<vector<char>>& board, char player)
{
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

bool isFull(const vector<vector<char>>& board)
{
    for (const auto& row : board)
        for (char c : row)
            if (c == EMPTY)
                return false;
    return true;
}

int minimax(vector<vector<char>>& board, bool isMax)
{
    if (hasWon(board, AI))
        return 10;
    if (hasWon(board, HUMAN))
        return -10;
    if (isFull(board))
        return 0;

    int best = isMax ? -1000 : 1000;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == EMPTY)
            {
                board[i][j] = isMax ? AI : HUMAN;
                int val = minimax(board, !isMax);
                board[i][j] = EMPTY;
                best = isMax ? max(best, val) : min(best, val);
            }
        }
    }
    return best;
}

pair<int, int> findBestMove(vector<vector<char>>& board)
{
    int bestVal = -1000;
    pair<int, int> bestMove = {-1, -1};
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == EMPTY)
            {
                board[i][j] = AI;
                int moveVal = minimax(board, false);
                board[i][j] = EMPTY;
                if (moveVal > bestVal)
                {
                    bestMove = {i, j};
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

void printBoard(const vector<vector<char>>& board)
{
    for (const auto& row : board)
    {
        for (char c : row) cout << c << ' ';
        cout << '\n';
    }
    cout << '\n';
}

int main()
{
    vector<vector<char>> board = {{AI, HUMAN, AI}, {HUMAN, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}};
    cout << "Current board:\n";
    printBoard(board);
    auto [r, c] = findBestMove(board);
    cout << "Best move for AI: (" << r << ", " << c << ")\n";
    return 0;
}

/*
Time Complexity: O(b^d) where b is branching factor (up to 9) and d is depth (up to 9) → O(9!) in
worst case. Space Complexity: O(d) — recursion depth up to 9.
*/
