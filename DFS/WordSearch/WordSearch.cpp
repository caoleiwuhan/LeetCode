//============================================================================
// Word Search
// Given a 2D board and a word, find if the word exists in the grid.
//
// The word can be constructed from letters of sequentially adjacent cell,
// where "adjacent" cells are those horizontally or vertically neighboring.
// The same letter cell may not be used more than once.
//
// For example,
// Given board =
//
// [
//   ["ABCE"],
//   ["SFCS"],
//   ["ADEE"]
// ]
// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.
//============================================================================

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    bool existHelper(vector<vector<char> > &board, vector<vector<bool> > &visited, int i, int j, string &word, int k) {
        if (board[i][j] != word[k]) return false;
        int L = word.size();
        if (k+1 == L) return true;
        int M = board.size();
        int N = board[0].size();
        visited[i][j] = true;
        if ((i > 0 && !visited[i-1][j]) && existHelper(board, visited, i-1, j, word, k+1)) return true;
        if ((i < M-1 && !visited[i+1][j]) && existHelper(board, visited, i+1, j, word, k+1)) return true;
        if ((j > 0 && !visited[i][j-1]) && existHelper(board, visited, i, j-1, word, k+1)) return true;
        if ((j < N-1 && !visited[i][j+1]) && existHelper(board, visited, i, j+1, word, k+1)) return true;
        visited[i][j] = false;
        return false;
    };

    bool exist(vector<vector<char> > &board, string word) {
        int M = board.size();
        if (M == 0) return 0;
        int N = board[0].size();
        if (N == 0) return 0;
        vector<vector<bool> > visited(M, vector<bool>(N, false));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (existHelper(board, visited, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    return 0;
}
