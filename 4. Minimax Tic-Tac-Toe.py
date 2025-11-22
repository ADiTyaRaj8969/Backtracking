"""
Minimax Algorithm for Tic-Tac-Toe
Minimax strategy: Maximize AI score while minimizing opponent score recursively; choose best move at each level.
Task: Implement the Minimax algorithm to create an unbeatable AI for the game of Tic-Tac-Toe. 
Write a function that takes the current board state and returns the optimal next move for the AI player.
"""

AI = 'X'
HUMAN = 'O'
EMPTY = '_'

def has_won(board, player):
    for i in range(3):
        if all(board[i][j] == player for j in range(3)): return True
        if all(board[j][i] == player for j in range(3)): return True
    if all(board[i][i] == player for i in range(3)): return True
    if all(board[i][2-i] == player for i in range(3)): return True
    return False

def is_full(board):
    return all(board[i][j] != EMPTY for i in range(3) for j in range(3))

def minimax(board, is_max):
    if has_won(board, AI): return 10
    if has_won(board, HUMAN): return -10
    if is_full(board): return 0

    best = -1000 if is_max else 1000
    for i in range(3):
        for j in range(3):
            if board[i][j] == EMPTY:
                board[i][j] = AI if is_max else HUMAN
                val = minimax(board, not is_max)
                board[i][j] = EMPTY
                best = max(best, val) if is_max else min(best, val)
    return best

def find_best_move(board):
    best_val = -1000
    best_move = (-1, -1)
    for i in range(3):
        for j in range(3):
            if board[i][j] == EMPTY:
                board[i][j] = AI
                move_val = minimax(board, False)
                board[i][j] = EMPTY
                if move_val > best_val:
                    best_move = (i, j)
                    best_val = move_val
    return best_move

def print_board(board):
    for row in board:
        print(' '.join(row))
    print()

if __name__ == "__main__":
    board = [
        [AI, HUMAN, AI],
        [HUMAN, EMPTY, EMPTY],
        [EMPTY, EMPTY, EMPTY]
    ]
    print("Current board:")
    print_board(board)
    r, c = find_best_move(board)
    print(f"Best move for AI: ({r}, {c})")

# Time Complexity: O(b^d) where b is branching factor (up to 9) and d is depth (up to 9) → O(9!) worst case.
# Space Complexity: O(d) — recursion depth up to 9.
