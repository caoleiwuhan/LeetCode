//============================================================================
// Search for a Range
// Given a sorted array of integers, find the starting and ending position of
// a given target value.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// If the target is not found in the array, return [-1, -1].
//
// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4].
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int l = lower_bound(A, n, target);
        int u = upper_bound(A, n, target) - 1;
        vector<int> res(2, -1);
        if (l > u) return res;
        res[0] = l;
        res[1] = u;
        return res;
    }

    int lower_bound(int A[], int n, int target) {
        int l = 0;
        int u = n - 1;
        while (l <= u) {
            int m = l + (u - l) / 2;
            if (A[m] >= target) u = m - 1;
            else l = m + 1;
        }
        return u + 1;
    }

    int upper_bound(int A[], int n, int target) {
        int l = 0;
        int u = n - 1;
        while (l <= u) {
            int m = l + (u - l) / 2;
            if (A[m] <= target) l = m + 1;
            else u = m - 1;
        }
        return l;
    }
};

int main() {
    int x[] = {5, 7, 7, 8, 8, 10}; 
    Solution sol;
    vector<int> res = sol.searchRange(x, sizeof(x)/sizeof(int), 8);
    cout << res[0] << "," << res[1] << endl;
    return 0;
}
