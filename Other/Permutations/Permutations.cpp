//============================================================================
// Given a collection of numbers, return all possible permutations.
//
// For example,
// [1,2,3] have the following permutations:
// [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
//============================================================================

#include <vector>
using namespace std;

class Solution {
public:
    void permuteHelper(vector<int> num, int i, vector<vector<int> > &result) {
        if (i == num.size()) result.push_back(num);
        else {
            for (int j = i; j < num.size(); j++) {
                swap(num[i], num[j]);
                permuteHelper(num, i + 1, result);
                swap(num[i], num[j]);
            }
        }
    }

    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        permuteHelper(num, 0, result);
        return result;
    }
};

int main() {
	return 0;
}
