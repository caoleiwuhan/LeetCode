//============================================================================
// Restore IP Addresses
// Given a string containing only digits, restore it by returning all possible
// valid IP address combinations.
//
// For example:
// Given "25525511135",
//
// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
//============================================================================

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.size() < 4 || s.size() > 12) return res;
        restoreIpAddressesHelper(s, 0, 4, "", res);
        return res;
    }

    void restoreIpAddressesHelper(string &s, size_t i, size_t k, string sol, vector<string> &res) {
        if (k < 0) return;
        if (i == s.size()) {
            if (k == 0) res.push_back(sol);
            return;
        }
        int x = 0;
        size_t j = i;
        while (j < s.size()) {
            x = 10*x+(s[j]-'0');
            if (x > 255) break;
            if (k != 4 && i == j) sol.push_back('.');
            sol.push_back(s[j++]);
            restoreIpAddressesHelper(s, j, k-1, sol, res);
            if (x == 0) break;
        }
    }
};

int main() {
   return 0;
}
