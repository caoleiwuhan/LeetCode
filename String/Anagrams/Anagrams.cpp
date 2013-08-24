//============================================================================
// Given an array of strings, return all groups of strings that are anagrams.
//
// Note: All inputs will be in lower-case.
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<string> > buffer;
        for (int i = 0; i < strs.size(); i++) {
            string copy(strs[i]);
            sort(copy.begin(), copy.end());
            buffer[copy].push_back(strs[i]);
        }
        vector<string> res;
        map<string, vector<string> >::iterator it = buffer.begin();
        while (it != buffer.end()) {
            vector<string> sub = it->second;
            if (sub.size() > 1)
                for (int i = 0; i < sub.size(); i++)
                    res.push_back(sub[i]);
            it++;
        }
        return res;
    }
};

int main() {
    return 0;
}
