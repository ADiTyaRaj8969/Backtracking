"""
Generate All Permutations
Backtracking strategy: Build permutations by swapping elements, backtrack after exploring each branch.
Task: Given an array of distinct integers, write a backtracking function to generate and return 
a list of all possible permutations of the numbers.
"""

def permute_helper(nums, start, result):
    if start == len(nums):
        result.append(nums[:])
        return
    for i in range(start, len(nums)):
        nums[start], nums[i] = nums[i], nums[start]
        permute_helper(nums, start + 1, result)
        nums[start], nums[i] = nums[i], nums[start]  # backtrack

def permute(nums):
    result = []
    permute_helper(nums, 0, result)
    return result

if __name__ == "__main__":
    nums = [1, 2, 3]
    perms = permute(nums)
    print("All permutations:")
    for perm in perms:
        print(' '.join(map(str, perm)))

# Time Complexity: O(n! * n) — n! permutations, each taking O(n) to copy.
# Space Complexity: O(n) — recursion depth.
