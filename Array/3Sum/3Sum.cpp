//============================================================================
// Given an array S of n integers, are there elements a, b, c in S such that
// a + b + c = 0?
// Find all unique triplets in the array which gives the sum of zero.
//
// Note:
// Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
// The solution set must not contain duplicate triplets.
// For example, given array S = {-1 0 1 2 -1 -4},
//
// A solution set is:
// (-1, 0, 1)
// (-1, -1, 2)
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int N = num.size();
        sort(num.begin(), num.end());
        vector<vector<int> > result;
        for (int k = 0; k < N-2; k++) {
            int i = k+1;
            int j = N-1;
            while (i < j) {
                int sum = num[i] + num[j] + num[k];
                if (sum > 0) j--;
                else if (sum < 0) i++;
                else {
                    vector<int> triplet;
                    triplet.push_back(num[i]);
                    triplet.push_back(num[j]);
                    triplet.push_back(num[k]);
                    sort(triplet.begin(), triplet.end());
                    if (find(result.begin(), result.end(), triplet) == result.end()) {
                        result.push_back(triplet);
                    }
                    i++;
                    j--;
                }
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
