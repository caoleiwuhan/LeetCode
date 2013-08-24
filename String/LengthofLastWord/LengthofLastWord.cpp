//============================================================================
// Given a string s consists of upper/lower-case alphabets and empty space
// characters ' ', return the length of last word in the string.
//
// If the last word does not exist, return 0.
//
// Note: A word is defined as a character sequence consists of non-space
// characters only.
//
// For example,
// Given s = "Hello World",
// return 5.
//============================================================================

#include <cstring>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int N = strlen(s);
        if (N == 0) return 0;
        int end = N - 1;
        while (end >= 0 && s[end] == ' ') end--;
        if (end < 0) return 0;
        int start = end - 1;
        while (start >= 0 && s[start] != ' ') start--;
        return end - start;
    }
};

int main() {
    return 0;
}
