//============================================================================
// Scramble String
// Given a string s1, we may represent it as a binary tree by partitioning it
// to two non-empty substrings recursively.
//
// Below is one possible representation of s1 = "great":
//
//    great
//   /    \
//  gr    eat
// / \    /  \
//g   r  e   at
//           / \
//          a   t
//To scramble the string, we may choose any non-leaf node and swap its two
// children.
//
//For example, if we choose the node "gr" and swap its two children, it
// produces a scrambled string "rgeat".
//
//    rgeat
//   /    \
//  rg    eat
// / \    /  \
//r   g  e   at
//           / \
//          a   t
//We say that "rgeat" is a scrambled string of "great".
//
//Similarly, if we continue to swap the children of nodes "eat" and "at", it
// produces a scrambled string "rgtae".
//
//    rgtae
//   /    \
//  rg    tae
// / \    /  \
//r   g  ta  e
//       / \
//      t   a
//We say that "rgtae" is a scrambled string of "great".
//
//Given two strings s1 and s2 of the same length, determine if s2 is a
// scrambled string of s1.
//============================================================================

#include <iostream>
using namespace std;

class Solution {
public:
    bool isSameCharSet(string &s1, int l1, int u1, string &s2, int l2, int u2) {
        if (u1 - l1 != u2 - l2) return false;
        int c[256] = {0};
        for (int i = l1; i < u1; i++) c[s1[i]]++;
        for (int i = l2; i < u2; i++) c[s2[i]]--;
        for (int i = 0; i < 256; i++)
            if (c[i] != 0) return false;
        return true;
    };

    bool isScrambleHelper(string &s1, int l1, int u1, string &s2, int l2, int u2) {
        if(!isSameCharSet(s1, l1, u1, s2, l2, u2)) return false;
        if (l1 + 1 == u1) return true;
        for (int i = 1; i < u1 - l1; i++) {
            if ((isScrambleHelper(s1, l1, l1 + i, s2, l2, l2 + i) && isScrambleHelper(s1, l1 + i, u1, s2, l2 + i, u2))
                    || (isScrambleHelper(s1, l1, l1 + i, s2, u2 - i, u2) && isScrambleHelper(s1, l1 + i, u1, s2, l2, u2 - i)))
                return true;
        }
        return false;
    };

    bool isScramble(string s1, string s2) {
        return isScrambleHelper(s1, 0, s1.size(), s2, 0, s2.size());
    };
};

int main() {
    return 0;
}
