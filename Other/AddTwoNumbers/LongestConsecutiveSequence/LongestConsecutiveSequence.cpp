//============================================================================
// Longest Consecutive Sequence
// Given an unsorted array of integers, find the length of the longest 
// consecutive elements sequence.
//
// For example,
// Given [100, 4, 200, 1, 3, 2],
// The longest consecutive elements sequence is [1, 2, 3, 4]. Return its 
// length: 4.
//
// Your algorithm should run in O(n) complexity.
//============================================================================

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num)
    {
        return longestConsecutive1(num);
    }

    int longestConsecutive1(vector<int> &num) 
    {
        if (num.empty()) return 0;
        sort(num.begin(), num.end());
        int res = 1;
        int count = 1;
        for (size_t i = 1; i < num.size(); ++i)
        {
            int diff = num[i] - num[i-1];
            if (diff == 0)
            {
                continue;
            }

            if (diff == 1)
            {
                count++;
                if (count > res)
                {
                    res = count;
                }
            }
            else
            {
                count = 1;
            }
        }
        return res;
    }

    int longestConsecutive2(vector<int> &num) 
    {
        if (num.empty()) return 0;
        unordered_map<int, int> table;
        int res = 1;
        for (size_t i = 0; i < num.size(); i++)
        {
            if (table.find(num[i]) != table.end()) continue;
            table[num[i]] = 1;
            
            if (table.find(num[i]-1) != table.end())
            {
                res = max(res, merge(table, num[i]-1, num[i])); 
            }

            if (table.find(num[i]+1) != table.end())
            {
                res = max(res, merge(table, num[i], num[i]+1));
            }
        }
        return res;
    }

    int merge(unordered_map<int, int> & table, int left, int right)
    {
        int lower = left - table[left] + 1;
        int upper = right + table[right] - 1;
        int len = upper - lower + 1;
        table[lower] = len;
        table[upper] = len;
        return len;
    }
};

int main() {
    vector<int> num = {100, 4, 200, 1, 3, 2};
    Solution sol;
    cout << sol.longestConsecutive(num) << endl;
    return 0;
}

