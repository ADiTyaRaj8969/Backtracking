"""
The N-Queens Problem ♛
Backtracking strategy: Place queens row by row, backtrack when a placement leads to an attack.
Task: Write a function that solves the N-Queens puzzle. It should take an integer n as input and 
return all distinct solutions for placing n non-attacking queens on an n x n chessboard.
"""

def is_safe(board, row, col):
    for i in range(row):
        if board[i] == col or abs(board[i] - col) == abs(i - row):
            return False
    return True

def solve_n_queens(n, row, board, solutions):
    if row == n:
        solutions.append(board[:])
        return
    for col in range(n):
        if is_safe(board, row, col):
            board[row] = col
            solve_n_queens(n, row + 1, board, solutions)
            board[row] = -1  # backtrack

def n_queens(n):
    solutions = []
    board = [-1] * n
    solve_n_queens(n, 0, board, solutions)
    return solutions

def print_solution(board):
    n = len(board)
    for i in range(n):
        print(' '.join('Q' if board[i] == j else '.' for j in range(n)))
    print()

if __name__ == "__main__":
    n = 4
    solutions = n_queens(n)
    print(f"Total solutions for {n}-Queens: {len(solutions)}\n")
    for sol in solutions:
        print_solution(sol)

# Time Complexity: O(n!) — explore n choices for first row, (n-1) for second, etc.
# Space Complexity: O(n) — recursion depth and board state.
