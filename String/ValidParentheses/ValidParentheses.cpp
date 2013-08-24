//============================================================================
// Valid Parentheses
// Given a string containing just the characters '(', ')', '{', '}', '[' and
// ']', determine if the input string is valid.
//
// The brackets must close in the correct order, "()" and "()[]{}" are all
// valid but "(]" and "([)]" are not.
//============================================================================

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
            }
            else {
                if (stk.empty()) return false;
                char c = stk.top();
                if ((c == '(' && s[i] == ')')
                        || (c == '{' && s[i] == '}')
                        || (c == '[' && s[i] == ']')) stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }
};

int main() {
    return 0;
}
