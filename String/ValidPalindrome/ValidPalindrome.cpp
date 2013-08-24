//============================================================================
// Given a string, determine if it is a palindrome, considering only 
// alphanumeric characters and ignoring cases.
//
// For example,
//
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int begin = 0, end = s.size()-1;
        while (begin < end) 
        {
            if (!isAlphanumeric(s[begin])) 
            {
                begin++;
                continue;
            }

            if (!isAlphanumeric(s[end]))
            {
                end--;
                continue;
            }

            int val = s[begin] - s[end];
            if (val != 0 && abs(val) != 32) 
            {
                return false;    
            }
            begin++;
            end--;
        }
        return true;
    }

    bool isAlphanumeric(char c) 
    {
        return ((c >= 'a' && c <= 'z') || 
                (c >= 'A' && c <= 'Z') || 
                (c >= '0' && c <= '9'));
    }
};

int main() 
{
    Solution sol;
    cout << sol.isPalindrome("1b2") << endl;
    return 0;
}
