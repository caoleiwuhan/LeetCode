//============================================================================
// Palindrome Partitioning
// Given a string s, partition s such that every substring of the partition 
// is a palindrome.
//
// Return all possible palindrome partitioning of s.
//
// For example, given s = "aab",
// Return
//
//   [
//       ["aa","b"],
//       ["a","a","b"]
//   ]
//============================================================================

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string> > res;
        vector<string> sub;
        partitionHelper(s, 0, sub, res);
        return res;
    }

    void partitionHelper(string const & s, size_t i, vector<string> sub, vector<vector<string> > & res)
    {
        if (i == s.size())
        {
            res.push_back(sub);
            return;
        }

        for (size_t j = i; j < s.size(); j++)
        {
            if (isPalindrome(s, i, j))
            {
                sub.push_back(s.substr(i, j-i+1));
                partitionHelper(s, j+1, sub, res);
                sub.pop_back();
            }
        }
    }

    bool isPalindrome(string const & s, size_t i, size_t j)
    {
        while (i < j)
            if (s[i++] != s[j--])
                return false;
        return true;
    }
};

int main()
{
    Solution sol;
    auto res = sol.partition("aab");
    for (auto it1 : res)
    {
        for(auto it2 : it1)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }
}
