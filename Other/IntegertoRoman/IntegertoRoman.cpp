//============================================================================
// Given an integer, convert it to a roman numeral.
//
// Input is guaranteed to be within the range from 1 to 3999.
//============================================================================

#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    map<int, string> dict;
    string intToRoman(int num) {
        dict.clear();
        dict[1] = "I";
        dict[4] = "IV";
        dict[5] = "V";
        dict[9] = "IX";
        dict[10] = "X";
        dict[40] = "XL";
        dict[50] = "L";
        dict[90] = "XC";
        dict[100] = "C";
        dict[400] = "CD";
        dict[500] = "D";
        dict[900] = "CM";
        dict[1000] = "M";
        string result = "";
        for (map<int, string>::reverse_iterator it = dict.rbegin(); it != dict.rend(); it++) {
            while (num >= it->first) {
                result += it->second;
                num -= it->first;
            }
        }
        return result;
    }
};
