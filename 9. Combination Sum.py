"""
Combination Sum
Backtracking strategy: Include candidate if it fits target; backtrack after exploring; candidates can be reused.
Task: Given an array of distinct integer candidates and a target integer, return a list of all 
unique combinations of candidates where the chosen numbers sum to the target. The same number may be used multiple times.
"""

def combination_sum_helper(candidates, target, start, current, result):
    if target == 0:
        result.append(current[:])
        return
    if target < 0:
        return
    for i in range(start, len(candidates)):
        current.append(candidates[i])
        combination_sum_helper(candidates, target - candidates[i], i, current, result)
        current.pop()  # backtrack

def combination_sum(candidates, target):
    result = []
    current = []
    candidates.sort()
    combination_sum_helper(candidates, target, 0, current, result)
    return result

if __name__ == "__main__":
    candidates = [2, 3, 6, 7]
    target = 7
    result = combination_sum(candidates, target)
    print(f"Combinations that sum to {target}:")
    for combo in result:
        print(' '.join(map(str, combo)))

# Time Complexity: O(2^target) — in worst case, each recursion level branches multiple times.
# Space Complexity: O(target) — recursion depth proportional to target value.
