//============================================================================
// Trapping Rain Water
// Given n non-negative integers representing an elevation map where the width
// of each bar is 1, compute how much water it is able to trap after raining.
//
// For example,
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
//============================================================================

#include <iostream>
using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        if (n <= 2) return 0;
        int lmax[n];
        int rmax[n];
        lmax[0] = A[0];
        for (int i = 1; i < n; i++) {
            lmax[i] = max(lmax[i - 1], A[i]);
        }
        rmax[n - 1] = A[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rmax[i] = max(rmax[i + 1], A[i]);
        }
        int total = 0;
        for (int i = 1; i < n - 1; i++) {
            int low = min(lmax[i - 1], rmax[i + 1]);
            total += (low > A[i]) ? (low - A[i]) : 0;
        }
        return total;
    }
};

int main() {
    return 0;
}
