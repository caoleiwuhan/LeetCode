//============================================================================
// Given two binary strings, return their sum (also a binary string).
//
// For example,
// a = "11"
// b = "1"
// Return "100".
//
//============================================================================

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string::iterator i = a.begin();
        string::iterator j = b.begin();
        string c;
        int carry = 0;
        while (true) {
            int ac, bc;
            if (i != a.end()) ac = *(i++) - '0';
            else ac = 0;
            if (j != b.end()) bc = *(j++) - '0';
            else bc = 0;
            int s = ac + bc + carry;
            c.push_back('0' + (s % 2));
            carry = s / 2;
            if (i == a.end() && j == b.end()) break;
        }
        if (carry == 1) c.push_back('1');
        reverse(c.begin(), c.end());
        return c;
    }
};

int main() {
    return 0;
}
