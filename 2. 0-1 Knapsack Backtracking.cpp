// 0/1 Knapsack using Backtracking
// Backtracking strategy: Explore all subsets by including/excluding each item, backtrack when
// capacity is exceeded. Task: Given a set of items, each with a weight and a value, determine the
// subset of items to include in a knapsack of a given capacity to get the maximum total value.
// Implement this using a pure backtracking approach that explores every possible subset.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void knapsackBacktrack(int idx, int currWeight, int currValue, int capacity,
                       const vector<int>& weights, const vector<int>& values, int& maxValue)
{
    if (idx == static_cast<int>(weights.size()))
    {
        maxValue = max(maxValue, currValue);
        return;
    }
    // Exclude current item
    knapsackBacktrack(idx + 1, currWeight, currValue, capacity, weights, values, maxValue);
    // Include current item if it fits
    if (currWeight + weights[idx] <= capacity)
    {
        knapsackBacktrack(idx + 1, currWeight + weights[idx], currValue + values[idx], capacity,
                          weights, values, maxValue);
    }
}

int knapsack01(const vector<int>& weights, const vector<int>& values, int capacity)
{
    int maxValue = 0;
    knapsackBacktrack(0, 0, 0, capacity, weights, values, maxValue);
    return maxValue;
}

int main()
{
    vector<int> weights = {10, 20, 30};
    vector<int> values = {60, 100, 120};
    int capacity = 50;
    cout << "Maximum value: " << knapsack01(weights, values, capacity) << '\n';
    return 0;
}

/*
Time Complexity: O(2^n) — explores all 2^n subsets of n items.
Space Complexity: O(n) — recursion depth.
*/
