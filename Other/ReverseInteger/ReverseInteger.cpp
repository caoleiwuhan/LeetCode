//============================================================================
// Reverse Integer
// Reverse digits of an integer.
//
// Example1: x = 123, return 321
// Example2: x = -123, return -321
//
// Have you thought about this?
// Here are some good questions to ask before coding. Bonus points for you if
// you have already thought through this!
//
// If the integer's last digit is 0, what should the output be? ie, cases such
// as 10, 100.
//
// Did you notice that the reversed integer might overflow? Assume the input
// is a 32-bit integer, then the reverse of 1000000003 overflows. How should
// you handle such cases?
//
// Throw an exception? Good, but what if throwing an exception is not an
// option? You would then have to re-design the function (ie, add an extra
// parameter).
//============================================================================

#include <cassert>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if (x < 0) sign = -sign, x = -x;
        long long res = 0;
        while (x) {
            res = res * 10 + x % 10;
            x /= 10;
        }
        assert(INT_MIN < res && INT_MAX > res);
        if (sign < 0) return -res;
        return res;
    }
};

int main() {
	return 0;
}
