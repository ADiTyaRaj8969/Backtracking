// Graph Coloring
// Backtracking strategy: Assign colors to vertices one by one; backtrack if no valid color exists
// for a vertex. Task: You are given an undirected graph and an integer m (the number of available
// colors). Write a function that determines if the graph can be colored with at most m colors such
// that no two adjacent vertices have the same color.

#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int v, const vector<vector<int>>& graph, const vector<int>& color, int c)
{
    for (int i = 0; i < static_cast<int>(graph.size()); ++i)
    {
        if (graph[v][i] && color[i] == c)
            return false;
    }
    return true;
}

bool graphColoringUtil(const vector<vector<int>>& graph, int m, vector<int>& color, int v)
{
    if (v == static_cast<int>(graph.size()))
        return true;
    for (int c = 1; c <= m; ++c)
    {
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;
            color[v] = 0;  // backtrack
        }
    }
    return false;
}

bool graphColoring(const vector<vector<int>>& graph, int m)
{
    int n = graph.size();
    vector<int> color(n, 0);
    return graphColoringUtil(graph, m, color, 0);
}

int main()
{
    vector<vector<int>> graph = {{0, 1, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 1}, {1, 0, 1, 0}};
    int m = 3;
    if (graphColoring(graph, m))
    {
        cout << "Graph can be colored with " << m << " colors.\n";
    }
    else
    {
        cout << "Graph cannot be colored with " << m << " colors.\n";
    }
    return 0;
}

/*
Time Complexity: O(m^V) — try m colors for each of V vertices.
Space Complexity: O(V) — recursion depth and color array.
*/
