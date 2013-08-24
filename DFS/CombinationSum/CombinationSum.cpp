//============================================================================
// Given a set of candidate numbers (C) and a target number (T),
// find all unique combinations in C where the candidate numbers sums to T.
//
// The same repeated number may be chosen from C unlimited number of times.
//
// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … ,ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.
// For example, given candidate set 2,3,6,7 and target 7,
// A solution set is:
// [7]
// [2, 2, 3]
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        sort(candidates.begin(), candidates.end());
        if (candidates[0] > target) return result;
        vector<int> combination;
        combinationSumHelper(candidates, target, 0, combination, result);
        return result;
    };

    void combinationSumHelper(vector<int> &candidates, int target, size_t i, vector<int> combination, vector<vector<int> > &result) {
        if (target <= 0) {
            if (target == 0)
                if (find(result.begin(), result.end(), combination) == result.end())
                    result.push_back(combination);
            return;
        }
        if (i == candidates.size()) return;
        for (int j = 0; j * candidates[i] <= target; j++) {
            if (j != 0) combination.push_back(candidates[i]);
            combinationSumHelper(candidates, target - j * candidates[i], i + 1, combination, result);
        }
    };
};

int main() {
    return 0;
}
