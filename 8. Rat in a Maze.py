"""
Rat in a Maze
Backtracking strategy: Move forward/down, mark path; backtrack if blocked or dead-end, unmark and try alternate route.
Task: A maze is given as a binary n x n matrix where 1s are open paths and 0s are blocked walls. 
A rat starts at (0, 0) and must reach (n-1, n-1). The rat can only move forward and down. 
Find and print one valid path from the start to the end.
"""

def is_safe(maze, x, y, n):
    return 0 <= x < n and 0 <= y < n and maze[x][y] == 1

def solve_maze_util(maze, x, y, sol, n):
    if x == n - 1 and y == n - 1:
        sol[x][y] = 1
        return True
    if is_safe(maze, x, y, n):
        sol[x][y] = 1
        # Move forward (right)
        if solve_maze_util(maze, x, y + 1, sol, n):
            return True
        # Move down
        if solve_maze_util(maze, x + 1, y, sol, n):
            return True
        sol[x][y] = 0  # backtrack
    return False

def solve_maze(maze):
    n = len(maze)
    sol = [[0] * n for _ in range(n)]
    if solve_maze_util(maze, 0, 0, sol, n):
        print("Path found:")
        for row in sol:
            print(' '.join(map(str, row)))
        return True
    print("No path exists")
    return False

if __name__ == "__main__":
    maze = [
        [1, 0, 0, 0],
        [1, 1, 0, 1],
        [0, 1, 0, 0],
        [1, 1, 1, 1]
    ]
    solve_maze(maze)

# Time Complexity: O(2^(n^2)) — at each cell, we can move in up to 2 directions (worst case).
# Space Complexity: O(n^2) — solution matrix and recursion depth.
