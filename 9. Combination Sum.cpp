// Combination Sum
// Backtracking strategy: Include candidate if it fits target; backtrack after exploring; candidates
// can be reused. Task: Given an array of distinct integer candidates and a target integer, return a
// list of all unique combinations of candidates where the chosen numbers sum to the target. The
// same number may be used multiple times.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void combinationSumHelper(const vector<int>& candidates, int target, int start,
                          vector<int>& current, vector<vector<int>>& result)
{
    if (target == 0)
    {
        result.push_back(current);
        return;
    }
    if (target < 0)
        return;
    for (int i = start; i < static_cast<int>(candidates.size()); ++i)
    {
        current.push_back(candidates[i]);
        combinationSumHelper(candidates, target - candidates[i], i, current, result);
        current.pop_back();  // backtrack
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> result;
    vector<int> current;
    sort(candidates.begin(), candidates.end());
    combinationSumHelper(candidates, target, 0, current, result);
    return result;
}

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    auto result = combinationSum(candidates, target);
    cout << "Combinations that sum to " << target << ":\n";
    for (const auto& combo : result)
    {
        for (int x : combo) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}

/*
Time Complexity: O(2^target) — in worst case, each recursion level branches multiple times.
Space Complexity: O(target) — recursion depth proportional to target value.
*/
