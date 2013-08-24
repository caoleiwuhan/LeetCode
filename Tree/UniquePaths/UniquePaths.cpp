//============================================================================
// Unique Paths
// A robot is located at the top-left corner of a m x n grid (marked 'Start'
// in the diagram below).
//
// The robot can only move either down or right at any point in time. The robot
// is trying to reach the bottom-right corner of the grid (marked 'Finish' in
// the diagram below).
//
// How many possible unique paths are there?
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        memset(dp, 0, sizeof(int)*m*n);
        dp[0][0] = 1;
        for (int i = 1; i < m; i++) dp[i][0] = dp[i-1][0];
        for (int j = 1; j < n; j++) dp[0][j] = dp[0][j-1];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    return 0;
}
