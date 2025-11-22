// Travelling Salesman Problem (TSP) using Branch and Bound 🗺️
// Branch and Bound strategy: Prune branches where the lower bound exceeds the current best
// solution. Task: You are given a weighted, complete graph representing cities and the distances
// between them. Implement a solution for the TSP using a Branch and Bound approach to find the
// minimum cost of a tour that visits every city exactly once and returns to the starting city.

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int calculateBound(const vector<vector<int>>& dist, vector<bool>& visited, int currCost, int level,
                   int n)
{
    int bound = currCost;
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            int minEdge = INT_MAX;
            for (int j = 0; j < n; ++j)
            {
                if (i != j && dist[i][j] < minEdge)
                {
                    minEdge = dist[i][j];
                }
            }
            if (minEdge != INT_MAX)
                bound += minEdge;
        }
    }
    return bound;
}

void tspBranchBound(const vector<vector<int>>& dist, vector<bool>& visited, int currCity, int count,
                    int currCost, int& minCost, int n, int start)
{
    if (count == n)
    {
        minCost = min(minCost, currCost + dist[currCity][start]);
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i] && dist[currCity][i] > 0)
        {
            visited[i] = true;
            int newCost = currCost + dist[currCity][i];
            int bound = calculateBound(dist, visited, newCost, count + 1, n);
            if (bound < minCost)
            {
                tspBranchBound(dist, visited, i, count + 1, newCost, minCost, n, start);
            }
            visited[i] = false;
        }
    }
}

int tsp(const vector<vector<int>>& dist)
{
    int n = dist.size();
    vector<bool> visited(n, false);
    visited[0] = true;
    int minCost = INT_MAX;
    tspBranchBound(dist, visited, 0, 1, 0, minCost, n, 0);
    return minCost;
}

int main()
{
    vector<vector<int>> dist = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
    cout << "Minimum tour cost: " << tsp(dist) << '\n';
    return 0;
}

/*
Time Complexity: O(n!) worst case, but pruning significantly reduces branches in practice.
Space Complexity: O(n) — recursion depth and visited array.
*/
