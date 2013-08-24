//============================================================================
// Spiral Matrix
// Given a matrix of m x n elements (m rows, n columns), return all elements
// of the matrix in spiral order.
//
// For example,
// Given the following matrix:
//
// [
// [ 1, 2, 3 ],
// [ 4, 5, 6 ],
// [ 7, 8, 9 ]
// ]
// You should return [1,2,3,6,9,8,7,4,5].
//============================================================================

#include <vector>
using namespace std;

class Solution {
public:
    void spiralOrderHelper(vector<vector<int> > &matrix, int M, int N, int k, vector<int> &res) {
        if (M <= 0 || N <= 0) return;
        if (M == 1) {
            for (int j = 0; j < N; j++) res.push_back(matrix[k][k+j]);
            return;
        }
        if (N == 1) {
            for (int i = 0; i < M; i++) res.push_back(matrix[k+i][k]);
            return;
        }
        int i = 0, j = 0;
        for (; j < N-1; j++) res.push_back(matrix[k+i][k+j]);
        for (; i < M-1; i++) res.push_back(matrix[k+i][k+j]);
        for (; j > 0; j--) res.push_back(matrix[k+i][k+j]);
        for (; i > 0; i--) res.push_back(matrix[k+i][k+j]);
        spiralOrderHelper(matrix, M-2, N-2, k+1, res);
    }

    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        int M = matrix.size();
        if (M == 0) return res;
        int N = matrix[0].size();
        if (N == 0) return res;
        spiralOrderHelper(matrix, M, N, 0, res);
        return res;
    }
};

int main() {
    return 0;
}
