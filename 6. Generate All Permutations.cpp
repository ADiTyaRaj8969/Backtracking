// Generate All Permutations
// Backtracking strategy: Build permutations by swapping elements, backtrack after exploring each
// branch. Task: Given an array of distinct integers, write a backtracking function to generate and
// return a list of all possible permutations of the numbers.

#include <iostream>
#include <vector>

using namespace std;

void permuteHelper(vector<int>& nums, int start, vector<vector<int>>& result)
{
    if (start == static_cast<int>(nums.size()))
    {
        result.push_back(nums);
        return;
    }
    for (int i = start; i < static_cast<int>(nums.size()); ++i)
    {
        swap(nums[start], nums[i]);
        permuteHelper(nums, start + 1, result);
        swap(nums[start], nums[i]);  // backtrack
    }
}

vector<vector<int>> permute(vector<int> nums)
{
    vector<vector<int>> result;
    permuteHelper(nums, 0, result);
    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    auto perms = permute(nums);
    cout << "All permutations:\n";
    for (const auto& perm : perms)
    {
        for (int x : perm) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}

/*
Time Complexity: O(n! * n) — n! permutations, each taking O(n) to copy.
Space Complexity: O(n) — recursion depth.
*/
