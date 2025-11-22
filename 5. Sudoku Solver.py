"""
Sudoku Solver
Backtracking strategy: Fill cells one by one; if a digit leads to invalid state, backtrack and try next digit.
Task: Write a function that solves a 9x9 Sudoku puzzle by filling the empty cells (represented by 0). 
The function should take a partially filled grid and modify it in-place to the solved state.
"""

def is_safe(board, row, col, num):
    if num in board[row] or num in (board[i][col] for i in range(9)):
        return False
    start_row, start_col = (row // 3) * 3, (col // 3) * 3
    for i in range(3):
        for j in range(3):
            if board[start_row + i][start_col + j] == num:
                return False
    return True

def solve_sudoku(board):
    for row in range(9):
        for col in range(9):
            if board[row][col] == 0:
                for num in range(1, 10):
                    if is_safe(board, row, col, num):
                        board[row][col] = num
                        if solve_sudoku(board):
                            return True
                        board[row][col] = 0  # backtrack
                return False
    return True

def print_board(board):
    for row in board:
        print(' '.join(map(str, row)))

if __name__ == "__main__":
    board = [
        [5, 3, 0, 0, 7, 0, 0, 0, 0],
        [6, 0, 0, 1, 9, 5, 0, 0, 0],
        [0, 9, 8, 0, 0, 0, 0, 6, 0],
        [8, 0, 0, 0, 6, 0, 0, 0, 3],
        [4, 0, 0, 8, 0, 3, 0, 0, 1],
        [7, 0, 0, 0, 2, 0, 0, 0, 6],
        [0, 6, 0, 0, 0, 0, 2, 8, 0],
        [0, 0, 0, 4, 1, 9, 0, 0, 5],
        [0, 0, 0, 0, 8, 0, 0, 7, 9]
    ]
    if solve_sudoku(board):
        print("Solved Sudoku:")
        print_board(board)
    else:
        print("No solution exists")

# Time Complexity: O(9^(n*n)) where n=9, worst case tries all possibilities for empty cells.
# Space Complexity: O(n*n) — recursion depth proportional to number of empty cells.
