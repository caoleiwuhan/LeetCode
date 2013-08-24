//============================================================================
// Write a function to find the longest common prefix string amongst an array
// of strings.
//============================================================================

#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int N = strs.size();
        if (N == 0) return "";
        int l = 0;
        while (l < strs[0].size()) {
            for (int i = 1; i < N; i++) {
                if (l == strs[i].size() || strs[i][l] != strs[0][l])
                    return strs[i].substr(0, l);
            }
            l++;
        }
        return strs[0];
    }
};

int main() {
    return 0;
}
