//============================================================================
// PlusOne
// Given a number represented as an array of digits, plus one to the number.
//============================================================================

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        reverse(digits.begin(), digits.end());
        int carry = 1;
        for (size_t i = 0; i < digits.size(); i++) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
            if (carry == 0) break;
        }
        if (carry != 0) digits.push_back(carry);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};

int main() {
	return 0;
}
