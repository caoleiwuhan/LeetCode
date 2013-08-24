//============================================================================
// Multiply Strings
//
// Given two numbers represented as strings, return multiplication of the
// numbers as a string.
//
// Note: The numbers can be arbitrarily large and are non-negative.
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        int n3 = n1+n2;
        int num3[n3];
        memset(num3, 0, sizeof(int)*(n3));
        for (int i = n1 - 1; i >= 0; i--) {
            int carry = 0, j, t;
            for (j = n2 - 1; j >= 0; j--) {
                t = carry + num3[i+j+1] + (num1[i]-'0') * (num2[j]-'0');
                num3[i+j+1] = t % 10;
                carry = t / 10;
            }
            num3[i+j+1] = carry;
        }
        string res = "";
        int i = 0;
        while (i < n3-1 && num3[i] == 0) i++;
        while (i < n3) res.push_back('0' + num3[i++]);
        return res;
    }
};

int main() {
    return 0;
}
