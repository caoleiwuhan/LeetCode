//============================================================================
// Given a string S and a string T, find the minimum window in S which will
// contain all the characters in T in complexity O(n).
//
// For example,
// S = "ADOBECODEBANC"
// T = "ABC"
// Minimum window is "BANC".
//
// Note:
// If there is no such window in S that covers all characters in T, return the
// empty string "".
//
// If there are multiple such windows, you are guaranteed that there will
// always be only one unique minimum window in S.
//============================================================================

#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        int needToFind[256] = {0};
        int hasFound[256] = {0};
        size_t count = 0;
        for (size_t i = 0; i < T.size(); i++)
            needToFind[(int)T[i]]++;

        string res = "";
        int min = INT_MAX;
        for (size_t begin = 0, end = 0; end < S.size(); end++) {
            if (needToFind[(int)S[end]] == 0) continue;
            hasFound[(int)S[end]]++;
            if (hasFound[(int)S[end]] <= needToFind[(int)S[end]]) count++;

            if (count == T.size()) {
                while (needToFind[(int)S[begin]] == 0 || hasFound[(int)S[begin]] > needToFind[(int)S[begin]]) {
                    if (hasFound[(int)S[begin]] > needToFind[(int)S[begin]]) hasFound[(int)S[begin]]--;
                    begin++;
                }

                int len = end - begin + 1;
                if (len < min) {
                    min = len;
                    res = S.substr(begin, len);
                }
            }
        }
        return res;
    }
};

int main() {
   return 0;
}
