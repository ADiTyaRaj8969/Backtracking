"""
Travelling Salesman Problem (TSP) using Branch and Bound 🗺️
Branch and Bound strategy: Prune branches where the lower bound exceeds the current best solution.
Task: You are given a weighted, complete graph representing cities and the distances between them. 
Implement a solution for the TSP using a Branch and Bound approach to find the minimum cost of a tour 
that visits every city exactly once and returns to the starting city.
"""

def calculate_bound(dist, visited, curr_cost, n):
    bound = curr_cost
    for i in range(n):
        if not visited[i]:
            min_edge = min((dist[i][j] for j in range(n) if i != j), default=float('inf'))
            if min_edge != float('inf'):
                bound += min_edge
    return bound

def tsp_branch_bound(dist, visited, curr_city, count, curr_cost, min_cost, n, start):
    if count == n:
        min_cost[0] = min(min_cost[0], curr_cost + dist[curr_city][start])
        return
    for i in range(n):
        if not visited[i] and dist[curr_city][i] > 0:
            visited[i] = True
            new_cost = curr_cost + dist[curr_city][i]
            bound = calculate_bound(dist, visited, new_cost, n)
            if bound < min_cost[0]:
                tsp_branch_bound(dist, visited, i, count + 1, new_cost, min_cost, n, start)
            visited[i] = False

def tsp(dist):
    n = len(dist)
    visited = [False] * n
    visited[0] = True
    min_cost = [float('inf')]
    tsp_branch_bound(dist, visited, 0, 1, 0, min_cost, n, 0)
    return min_cost[0]

if __name__ == "__main__":
    dist = [
        [0, 10, 15, 20],
        [10, 0, 35, 25],
        [15, 35, 0, 30],
        [20, 25, 30, 0]
    ]
    print(f"Minimum tour cost: {tsp(dist)}")

# Time Complexity: O(n!) worst case, but pruning significantly reduces branches in practice.
# Space Complexity: O(n) — recursion depth and visited array.
