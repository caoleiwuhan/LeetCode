//============================================================================
// Spiral Matrix II
// Given an integer n, generate a square matrix filled with elements from 1 to
// n2 in spiral order.
//
// For example,
// Given n = 3,
//
// You should return the following matrix:
// [
// [ 1, 2, 3 ],
// [ 8, 9, 4 ],
// [ 7, 6, 5 ]
// ]
//============================================================================


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void generateMatrixHelper(vector<vector<int> > &res, int x, int n, int k) {
        if (n <= 0) return;
        if (n == 1) {
            res[k+n-1][k+n-1] = x++;
            return;
        }
        int i = 0, j = 0;
        for (; j < n-1; j++) res[k+i][k+j] = x++;
        for (; i < n-1; i++) res[k+i][k+j] = x++;
        for (; j > 0; j--) res[k+i][k+j] = x++;
        for (; i > 0; i--) res[k+i][k+j] = x++;
        generateMatrixHelper(res, x, n-2, k+1);
    }

    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res;
        for (int i = 0; i < n; i++) {
            res.push_back(vector<int>(n, 0));
        }
        generateMatrixHelper(res, 1, n, 0);
        return res;
    }
};


int main() {
    return 0;
}
