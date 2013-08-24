//============================================================================
// Given a string containing just the characters '(' and ')', find the length
// of the longest valid (well-formed) parentheses substring.
//
// For "(()", the longest valid parentheses substring is "()", which has
// length = 2.
//
// Another example is ")()())", where the longest valid parentheses substring
// is "()()", which has length = 4.
//============================================================================

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int N = s.size();
        if (N < 2) return 0;
        int res = 0;
        int k = 0, l = 0;
        for (int i = 0; i < N; i++) {
            if (s[i] == '(') k++, l++;
            else k--, l++;
            if (k == 0 && l > res) res = l;
            else if (k < 0) k = 0, l = 0;
        }

        k = 0, l = 0;
        for (int i = N-1; i > 0; i--) {
            if (s[i] == ')') k++, l++;
            else k--, l++;
            if (k == 0 && l > res) res = l;
            else if (k < 0) k = 0, l = 0;
        }
        return res;
    }
};

int main() {
	return 0;
}
