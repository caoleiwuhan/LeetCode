//============================================================================
// N-Queens II
// Follow up for N-Queens problem.
//
// Now, instead outputting board configurations, return the total number of
// distinct solutions.
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isSafe(int board[], int n, int row, int col) {
        for (int j = 0; j < col; j++)
            if (board[j] == row || abs(board[j] - row) == col - j)
                return false;
        return true;
    }

    void totalNQueensHelper(int board[], int n, int col, int &count) {
        if (col == n) count++;
        for (int row = 0; row < n; row++) {
            if (isSafe(board, n, row, col)) {
                board[col] = row;
                totalNQueensHelper(board, n, col+1, count);
            }
        }
    };

    int totalNQueens(int n) {
        int count = 0;
        int board[n];
        totalNQueensHelper(board, n, 0, count);
        return count;
    };
};

int main() {
	return 0;
}
