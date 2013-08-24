//============================================================================
// Implement strStr().
//
// Returns a pointer to the first occurrence of needle in haystack,
// or null if needle is not part of haystack.
//============================================================================

#include <cstring>

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (!haystack || !needle) return haystack;
        int n = strlen(haystack);
        int m = strlen(needle);
        int i = 0;
        while (i < n-m+1) {
            int j = 0;
            while (j < m && haystack[i] == needle[j]) {
                i++, j++;
            }
            if (j == m) return haystack+(i-j);
            i = i-j+1;
        }
        return NULL;
    }
};

int main() {
    return 0;
}
