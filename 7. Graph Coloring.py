"""
Graph Coloring
Backtracking strategy: Assign colors to vertices one by one; backtrack if no valid color exists for a vertex.
Task: You are given an undirected graph and an integer m (the number of available colors). 
Write a function that determines if the graph can be colored with at most m colors such that 
no two adjacent vertices have the same color.
"""

def is_safe(v, graph, color, c):
    for i in range(len(graph)):
        if graph[v][i] and color[i] == c:
            return False
    return True

def graph_coloring_util(graph, m, color, v):
    if v == len(graph):
        return True
    for c in range(1, m + 1):
        if is_safe(v, graph, color, c):
            color[v] = c
            if graph_coloring_util(graph, m, color, v + 1):
                return True
            color[v] = 0  # backtrack
    return False

def graph_coloring(graph, m):
    n = len(graph)
    color = [0] * n
    return graph_coloring_util(graph, m, color, 0)

if __name__ == "__main__":
    graph = [
        [0, 1, 1, 1],
        [1, 0, 1, 0],
        [1, 1, 0, 1],
        [1, 0, 1, 0]
    ]
    m = 3
    if graph_coloring(graph, m):
        print(f"Graph can be colored with {m} colors.")
    else:
        print(f"Graph cannot be colored with {m} colors.")

# Time Complexity: O(m^V) — try m colors for each of V vertices.
# Space Complexity: O(V) — recursion depth and color array.
