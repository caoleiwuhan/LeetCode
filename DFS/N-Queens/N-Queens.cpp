//============================================================================
// N-Queens
//
// The n-queens puzzle is the problem of placing n queens on an n×n chessboard
// such that no two queens attack each other.
//============================================================================

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isSafe(vector<string> &board, int row, int col) {
        int N = board.size();
        int i = row, j = 0;
        while(j < col)
            if (board[i][j++] == 'Q') return false;
        i = row, j = col;
        while (i >=0 && j >= 0)
            if (board[i--][j--] == 'Q') return false;
        i = row, j = col;
        while (i < N && j >= 0)
            if (board[i++][j--] == 'Q') return false;
        return true;
    };

    void solveNQueensHelper(vector<string> &board, int col, vector<vector<string> > &result) {
        int N = board.size();
        if (col == N) {
            result.push_back(board);
            return;
        }
        for(int i = 0; i < N; i++) {
            if (isSafe(board, i, col)) {
                board[i][col] = 'Q';
                solveNQueensHelper(board, col + 1, result);
                board[i][col] = '.';
            }
        }
    };

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
        string row(n, '.');
        vector<string> board(n, row);
        solveNQueensHelper(board, 0, result);
        return result;
    }
};
int main() {
	return 0;
}
