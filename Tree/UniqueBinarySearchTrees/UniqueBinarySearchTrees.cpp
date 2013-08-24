//============================================================================
// Unique Binary Search Trees
// Given n, how many structurally unique BST's (binary search trees) that
// store values 1...n?
//
// For example,
// Given n = 3, there are a total of 5 unique BST's.
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3
//
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
//        return numTrees1(n);
        return numTrees2(n);
    }

    int numTrees1(int n) {
        if (n < 2) return 1;
        int res = 0;
        for (int i = 0; i < n; i++)
            res += numTrees1(i)*numTrees1(n-i-1);
        return res;
    }

    int numTrees2(int n) {
        int dp[n+1];
        memset(dp, 0, (n+1)*sizeof(int));
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};

int main() {
    Solution sol;
    sol.numTrees(3);
    return 0;
}
