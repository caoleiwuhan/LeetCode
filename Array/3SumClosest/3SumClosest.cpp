//============================================================================
// Given an array S of n integers, find three integers in S such that the sum
// is closest to a given number, target. Return the sum of the three integers.
// You may assume that each input would have exactly one solution.
//
// For example, given array S = {-1 2 1 -4}, and target = 1.
//
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int N = num.size();
        sort(num.begin(), num.end());
        int res = num[0] + num[1] + num[2];
        for (int k = 0; k < N-2; k++) {
            int i = k+1;
            int j = N-1;
            while (i < j) {
                int sum = num[i] + num[j] + num[k];
                if (sum == target) return sum;
                if (abs(sum-target) < abs(res-target)) res = sum;
                if (sum > target) j--;
                else i++;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
