//============================================================================
// Palindrome Partitioning II
// Given a string s, partition s such that every substring of the partition 
// is a palindrome.
//
// Return the minimum cuts needed for a palindrome partitioning of s.
//
// For example, given s = "aab",
// Return 1 since the palindrome partitioning ["aa","b"] could be produced 
// using 1 cut.
//
//============================================================================

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minCut(string s)
    {
        if (s.empty()) return 0;
        int N = s.size();
        
        vector<vector<bool> > dp1(N, vector<bool>(N, false));
        for (int i = N-1; i >= 0; i--)
            for (int j = i; j < N; j++)
                if (i == j) 
                    dp1[i][j] = true;
                else if (i + 1 == j) 
                    dp1[i][j] = (s[i] == s[j]);
                else 
                    dp1[i][j] = (s[i] == s[j] && dp1[i+1][j-1]);

        vector<int> dp2(N+1, 0);
        dp2[0] = -1;
        for (int i = 2; i <= N; i++)
        {
            dp2[i] = dp2[i-1] + 1;
            for (int j = i-2; j >= 0; j--)
                if (dp1[j][i-1])
                    dp2[i] = min(dp2[i], 1 + dp2[j]);
        }

        return dp2[N];
    }
};

int main()
{
    Solution sol;
    auto res = sol.minCut("abbab");
    cout << res << endl;
}
