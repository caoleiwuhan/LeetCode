//============================================================================
// Distinct Subsequences
// Given a string S and a string T, count the number of distinct subsequences
// of T in S.
//
// A subsequence of a string is a new string which is formed from the original
// string by deleting some (can be none) of the characters without disturbing
// the relative positions of the remaining characters. (ie, "ACE" is a
// subsequence of "ABCDE" while "AEC" is not).
//
// Here is an example:
// S = "rabbbit", T = "rabbit"
//
// Return 3.
//============================================================================

#include <iostream>
using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        int N = S.size();
        int M = T.size();
        int dp[M+1][N+1];
        dp[0][0] = 1;
        for (int i = 1; i <= M; i++) dp[i][0] = 0;
        for (int j = 1; j <= N; j++) dp[0][j] = 1;
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (T[i-1] == S[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                else dp[i][j] = dp[i][j-1];
            }
        }
        return dp[M][N];
    }
};

int main() {
    return 0;
}
