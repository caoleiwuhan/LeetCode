//============================================================================
// Given n pairs of parentheses, write a function to generate all combinations
// of well-formed parentheses.
//
// For example, given n = 3, a solution set is:
//
// "((()))", "(()())", "(())()", "()(())", "()()()"
//============================================================================

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesisHeler(n, n, "", result);
        return result;
    };

    void generateParenthesisHeler(int l, int r, string s, vector<string> &result) {
        if (l == 0 && r == 0) result.push_back(s);
        if (l > 0) generateParenthesisHeler(l - 1, r, s + '(', result);
        if (r > l) generateParenthesisHeler(l, r - 1, s + ')', result);
    };
};

int main() {
    return 0;
}
