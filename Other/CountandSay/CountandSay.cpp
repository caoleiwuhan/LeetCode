//============================================================================
// The count-and-say sequence is the sequence of integers beginning as follows:
// 1, 11, 21, 1211, 111221, ...
//
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth sequence.
//
// Note: The sequence of integers will be represented as a string.
//
//
//============================================================================

#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n < 1) return "";
        string res("1");
        while (n > 1) {
            ostringstream oss;
            int i = 0;
            while (i < res.size()) {
                int j = i;
                while (j < res.size() && res[j] == res[i]) j++;
                oss << (j-i) << res[i];
                i = j;
            }
            res = oss.str();
            n--;
        }
        return res;
    }
};

int main() {
    return 0;
}
