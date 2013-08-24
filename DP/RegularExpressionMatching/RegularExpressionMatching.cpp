//============================================================================
// Regular Expression Matching
// Implement regular expression matching with support for '.' and '*'.
//
// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
//
// The matching should cover the entire input string (not partial).
//
// The function prototype should be:
// bool isMatch(const char *s, const char *p)
//
// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "a*") → true
// isMatch("aa", ".*") → true
// isMatch("ab", ".*") → true
// isMatch("aab", "c*a*b") → true
//============================================================================

#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        assert(s && p);
        if (*p == '\0') return *s == '\0';

        if (*(p+1) != '*') {
            assert(*p != '*');
            return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
        }
        // next char is '*'
        while ((*p == *s) || (*p == '.' && *s != '\0')) {
            if (isMatch(s, p+2)) return true;
            s++;
        }
        return isMatch(s, p+2);
    };
};

int main() {
    return 0;
}
