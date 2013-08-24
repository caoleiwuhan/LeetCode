//============================================================================
// Given an array of integers, find two numbers such that they add up to a
// specific target number.
//
// The function twoSum should return indices of the two numbers such that they
// add up to the target,
// where index1 must be less than index2.
// Please note that your returned answers (both index1 and index2) are not
// zero-based.
//
// You may assume that each input would have exactly one solution.
//
// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int N = numbers.size();
        vector<int> copy(numbers.begin(), numbers.end());
        sort(copy.begin(), copy.end());
        int i = 0;
        int j = N - 1;
        while (i < j) {
            int sum = copy[i] + copy[j];
            if (sum > target) j--;
            else if (sum < target) i++;
            else
                break;
        }
        vector<int> res;
        for (int k = 0; k < N; k++) {
            if (copy[i] == numbers[k]) {
                res.push_back(k + 1);
                break;
            }
        }
        for (int k = 0; k < N; k++) {
            if (copy[j] == numbers[k] && (k + 1) != res[0]) {
                res.push_back(k + 1);
                break;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    return 0;
}
