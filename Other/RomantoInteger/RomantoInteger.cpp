//============================================================================
// Roman to Integer
// Given a roman numeral, convert it to an integer.
//
// Input is guaranteed to be within the range from 1 to 3999.
//============================================================================

#include <map>
#include <string>
using namespace std;

class Solution {
public:
    map<char, int> dict;
    int romanToInt(string s) {
        dict['M'] = 1000;
        dict['D'] = 500;
        dict['C'] = 100;
        dict['L'] = 50;
        dict['X'] = 10;
        dict['V'] = 5;
        dict['I'] = 1;
        int res = 0;
        size_t i = 0;
        while (i < s.size() - 1) {
            if (dict[s[i]] < dict[s[i+1]]) res -= dict[s[i]];
            else res += dict[s[i]];
            i++;
        }
        res += dict[s[i]];
        return res;
    }
};

int main() {
    Solution sol;
    sol.romanToInt("MMMMM");
    return 0;
}
