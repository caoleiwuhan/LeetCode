//============================================================================
// Given a string S, find the longest palindromic substring in S. You may
// assume that the maximum length of S is 1000, and there exists one unique
// longest palindromic substring.
//============================================================================

#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        return longestPalindrome1(s);    
    }    
    
    // take O(n^2) time, O(n^2) space
    string longestPalindrome1(string s) {
        int n = s.size();
        if (n == 0) return ""; 
        int maxi = 0;
        int maxl = 1;
        bool dp[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = false;
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }   
        for (int i = 0; i < n-1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                maxl = 2;
                maxi = i;
            }   
        }   
        for (int l = 3; l <= n; l++) {
            for (int i = 0; i < n-l+1; i++) {
                int j = i+l-1;
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    maxl = l;
                    maxi = i;
                }   
            }   
        }   
        return s.substr(maxi, maxl);
    }
    
    // take O(n^2) time, O(1) space
    string longestPalindrome2(string s) {
        int n = s.size();
        if (n == 0) return "";
        int maxi = 0;
        int maxl = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                int start = i - j;
                int end = i + 1;
                while (start >= 0 && end < n && s[start] == s[end])
                    start--, end++;
                start++, end--;
                int len = end - start + 1;
                if (len > maxl) maxi = start, maxl = len;
            }
        }
        return s.substr(maxi, maxl);
    }
};

int main() {
    return 0;
}
