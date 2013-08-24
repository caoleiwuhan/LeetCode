//============================================================================
// Wildcard Matching
// Implement wildcard pattern matching with support for '?' and '*'.
//
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
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
// isMatch("aa", "*") → true
// isMatch("aa", "a*") → true
// isMatch("ab", "?*") → true
// isMatch("aab", "c*a*b") → false
//============================================================================

#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(const char* s, const char* p) {
        return isMatch1(s, p);
    }

    bool isMatch1(const char* s, const char* p) {
        if (*s == '\0') {
            if (*p == '\0') return true;
            if (*p == '*') return isMatch(s,p+1);
            return false;
        }
        if (*p == '\0') return false;
        if (*p == '?' || *p == *s) return isMatch(s+1, p+1);
        if (*p=='*') return isMatch(s+1,p) || isMatch(s, p+1);
        return false;
    }

    bool isMatch2(const char* s, const char* p) {
        const char *ps, *pp;
        bool star = false;
        loopStart:
        for (ps = s, pp = p; *ps; ++ps, ++pp) {
            switch (*pp) {
            case '?':
                break;
            case '*':
                star = true;
                s = ps, p = pp+1;
                if (!*p) return true;
                goto loopStart;
            default:
                if (*ps != *pp)
                    goto starCheck;
                break;
            }
        }
        while (*pp == '*') ++pp;
        return (!*pp);
        starCheck:
        if (!star) return false;
        s++;
        goto loopStart;
        return false;
    }
};

int main() {
    return 0;
}
