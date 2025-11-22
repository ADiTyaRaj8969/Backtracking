"""
0/1 Knapsack using Backtracking
Backtracking strategy: Explore all subsets by including/excluding each item, backtrack when capacity is exceeded.
Task: Given a set of items, each with a weight and a value, determine the subset of items to include 
in a knapsack of a given capacity to get the maximum total value. Implement this using a pure backtracking 
approach that explores every possible subset.
"""

def knapsack_backtrack(idx, curr_weight, curr_value, capacity, weights, values, max_value):
    if idx == len(weights):
        max_value[0] = max(max_value[0], curr_value)
        return
    # Exclude current item
    knapsack_backtrack(idx + 1, curr_weight, curr_value, capacity, weights, values, max_value)
    # Include current item if it fits
    if curr_weight + weights[idx] <= capacity:
        knapsack_backtrack(idx + 1, curr_weight + weights[idx], curr_value + values[idx], 
                           capacity, weights, values, max_value)

def knapsack_01(weights, values, capacity):
    max_value = [0]
    knapsack_backtrack(0, 0, 0, capacity, weights, values, max_value)
    return max_value[0]

if __name__ == "__main__":
    weights = [10, 20, 30]
    values = [60, 100, 120]
    capacity = 50
    print(f"Maximum value: {knapsack_01(weights, values, capacity)}")

# Time Complexity: O(2^n) — explores all 2^n subsets of n items.
# Space Complexity: O(n) — recursion depth.
