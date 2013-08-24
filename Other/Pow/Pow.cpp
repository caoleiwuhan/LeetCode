//============================================================================
// Pow(x, n)
// Implement pow(x, n).
//============================================================================

class Solution {
public:
    double pow(double x, int n) {
        return pow1(x, n);
    }

    double pow1(double x, int n) {
        int sign = 1;
        if (n < 0) sign = -sign, n = -n;
        double tmp = x, res = 1.0;
        for (int t = n; t > 0; t /= 2) {
            if(t % 2 == 1) res *= tmp;
            tmp = tmp * tmp;
        }
        if (sign < 0) return 1.0 / res;
        return res;
    }

    double pow2(double x, int n) {
        int sign = 1;
        if (n < 0) sign = -sign, n = -n; 
        double res = powHelper(x, n); 
        if(sign < 0) return 1.0 / res;
        return res;
    }

    double powHelper(double x, unsigned int n) {
        if (n == 0) return 1.0;
        if (n == 1) return x;
        double t = powHelper(x, n / 2); 
        if (n%2 == 0) return t*t;
        return x*t*t;
    }
};

int main() {
    return 0;
}
