//============================================================================
// Divide two integers without using multiplication, division and mod operator.
//============================================================================

class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1;
        unsigned int unsigned_dividend, unsigned_divisor;
        if (dividend < 0) {
            unsigned_dividend = -dividend;
            sign = -sign;
        }
        else unsigned_dividend = dividend;
        if (divisor < 0) {
            unsigned_divisor = -divisor;
            sign = -sign;
        }
        else unsigned_divisor = divisor;
        unsigned int result = unsigned_divide(unsigned_dividend, unsigned_divisor);
        return (sign < 0) ? -result : result;
    }

    unsigned int unsigned_divide(unsigned int dividend, unsigned int divisor) {
        unsigned int quotient = 0;
        while (dividend >= divisor) {
            unsigned int tmp = divisor;
            unsigned int shift = 0;
            while (((unsigned long long)tmp << 1) <= dividend) {
                tmp <<= 1;
                shift++;
            }
            dividend -= tmp;
            quotient |= (1 << shift);
        }
        return quotient;
    }
};

int main() {
    return 0;
}
