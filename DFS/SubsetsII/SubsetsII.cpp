//============================================================================
// Subsets II
// Given a collection of integers that might contain duplicates, S, return all
// possible subsets.
//
// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// For example,
// If S = [1,2,2], a solution is:
//
// [
//  [2],
//  [1],
//  [1,2,2],
//  [2,2],
//  [1,2],
//  []
// ]
//============================================================================

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        int N = S.size();
        int max = 1 << N;
        vector<vector<int> > res;
        for (int i = 0; i < max; i++) {
            vector<int> sub;
            int k = i;
            int j = 0;
            while (k > 0) {
                if (k & 0x01) sub.push_back(S[j]);
                k >>= 1;
                j++;
            }
            sort(sub.begin(), sub.end());
            if (find(res.begin(), res.end(), sub) == res.end()) {
                res.push_back(sub);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    return 0;
}
