//============================================================================
// Given a string, find the length of the longest substring without repeating
// characters. For example,
//
// the longest substring without repeating letters for "abcabcbb" is "abc",
// which the length is 3. For "bbbbb" the longest substring is "b", with the
// length of 1.
//============================================================================

#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t res = 0;
        size_t start = 0, end = 0;
        bool visited[256] = { false };
        while (end < s.size()) {
            if (visited[(int)s[end]]) {
                res = max(res, end - start);
                while (s[start] != s[end]) visited[(int)s[start++]] = false;
                start++;
                end++;
            } else {
                visited[(int)s[end]] = true;
                end++;
            }
        }
        res = max(res, end - start);
        return res;
    }
};

int main() {
    return 0;
}
