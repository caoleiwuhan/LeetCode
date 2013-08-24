//============================================================================
// Decode Ways
// A message containing letters from A-Z is being encoded to numbers using
// the following mapping:
//
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given an encoded message containing digits, determine the total number of
// ways to decode it.
//
// For example,
// Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
//
// The number of ways decoding "12" is 2.
//============================================================================

#include <iostream>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int N = s.size();
        if (N == 0) return 0;
        if (s[0] == '0') return 0;
        int dp[N+1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= N; i++) {
            if (s[i-2] == '1') {
                if (s[i-1] == '0') dp[i] = dp[i-2];
                else dp[i] = dp[i-1] + dp[i-2];
            }
            else if (s[i-2] == '2') {
                if (s[i-1] == '0') dp[i] = dp[i-2];
                else if (s[i-1] > '6') dp[i] = dp[i-1];
                else dp[i] = dp[i-1] + dp[i-2];
            }
            else {
                if (s[i-1] == '0') return 0;
                dp[i] = dp[i-1];
            }
        }
        return dp[N];
    }
};

int main() {
    return 0;
}
