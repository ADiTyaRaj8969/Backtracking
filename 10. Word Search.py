"""
Word Search Solver
Backtracking strategy: For each cell, try all 4 directions; mark visited; backtrack if path fails, unmark and try next direction.
Task: Given a 2D grid of characters and a word, write a function that finds if the word exists in the grid. 
The word can be constructed from letters in sequentially adjacent cells, where "adjacent" cells are those 
horizontally or vertically neighboring. The same letter cell may not be used more than once.
"""

def dfs(board, word, idx, r, c):
    if idx == len(word):
        return True
    if r < 0 or r >= len(board) or c < 0 or c >= len(board[0]) or board[r][c] != word[idx]:
        return False
    
    temp = board[r][c]
    board[r][c] = '#'  # mark visited
    
    found = (dfs(board, word, idx + 1, r + 1, c) or
             dfs(board, word, idx + 1, r - 1, c) or
             dfs(board, word, idx + 1, r, c + 1) or
             dfs(board, word, idx + 1, r, c - 1))
    
    board[r][c] = temp  # backtrack
    return found

def word_search(board, word):
    for i in range(len(board)):
        for j in range(len(board[0])):
            if dfs(board, word, 0, i, j):
                return True
    return False

if __name__ == "__main__":
    board = [
        ['A', 'B', 'C', 'E'],
        ['S', 'F', 'C', 'S'],
        ['A', 'D', 'E', 'E']
    ]
    word = "ABCCED"
    if word_search(board, word):
        print(f"Word '{word}' found in grid.")
    else:
        print(f"Word '{word}' not found in grid.")

# Time Complexity: O(m*n*4^L) where m,n are grid dimensions and L is word length (4 directions per cell).
# Space Complexity: O(L) — recursion depth equals word length.
