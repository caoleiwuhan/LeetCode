//============================================================================
// Given a digit string, return all possible letter combinations that the
// number could represent.
//
// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Note:
// Although the above answer is in lexicographical order, your answer could be
// in any order you want.
//============================================================================

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    static const string keypad[8];
    vector<string> result;
    vector<string> letterCombinations(string digits) {
        result.clear();
        letterCombinationsHelper(digits, 0, "");
        return result;
    }

    void letterCombinationsHelper(string& digits, size_t i, string str) {
        if (i == digits.size()) {
            result.push_back(str);
        }
        int pos = digits[i] - '2';
        for (size_t j = 0; j < keypad[pos].size(); j++) {
            letterCombinationsHelper(digits, i + 1, str + keypad[pos][j]);
        }
    }
};
const string Solution::keypad[8]  = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int main() {
    return 0;
}
