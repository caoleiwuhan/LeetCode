//============================================================================
// Find the contiguous subarray within an array (containing at least one
// number) which has the largest sum.
//
// For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
// the contiguous subarray [4,−1,2,1] has the largest sum = 6.
//============================================================================

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSumSubarray(const int x[], const int n) {
        return maxSumSubarray1(x, n);
    }

    int maxSumSubarray1(const int x[], const int n) {
        int res = x[0];
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = 0;
                for (int k = i; k <= j; k++) sum += x[k];
                if (sum > res) res = sum;
            }
        }
        return res;
    };

    int maxSumSubarray2(const int x[], const int n) {
        int res = x[0];
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += x[j];
                if (sum > res) res = sum;
            }
        }
        return res;
    };

    int maxSumSubarray3(const int x[], const int l, const int u) {
        if (l > u) return INT_MIN;
        if (l == u) return x[l];
        int m = (l + u) / 2;
        int lmax, rmax, sum;
        sum = 0;
        lmax = x[m];
        for (int i = m; i >= l; i--)
            sum += x[i], lmax = max(lmax, sum);
        sum = 0;
        rmax = x[m];
        for (int i = m; i <= u; i++)
            sum += x[i], rmax = max(rmax, sum);
        int res = max(maxSumSubarray3(x, m + 1, u), maxSumSubarray3(x, l, m - 1));
        return max(res, lmax + rmax - x[m]);
    };

    int maxSumSubarray4(const int x[], const int n) {
        int maxSoFar = INT_MIN;
        int i;
        for (i = 0; i < n; i++) {
            if (x[i] >= 0) break;
            maxSoFar = max(maxSoFar, x[i]);
        }
        // if all negative return max elements
        if (i == n) return maxSoFar;

        // otherwise, return the maximum sub array
        int maxEndHere = 0;
        for (i = 0; i < n; i++) {
            maxEndHere += x[i];
            if (maxEndHere < 0) maxEndHere = 0;
            if (maxEndHere > maxSoFar) maxSoFar = maxEndHere;
        }
        return maxSoFar;
    };
};

int main() {
    return 0;
}
