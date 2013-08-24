//============================================================================
// Permutation Sequence
// The set [1,2,3,…,n] contains a total of n! unique permutations.
//
// By listing and labeling all of the permutations in order,
// We get the following sequence (ie, for n = 3):
//
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.
//
// Note: Given n will be between 1 and 9 inclusive.
//============================================================================

#include <string>
#include <cassert>
using namespace std;

class Solution {
public:
    void reverse(string &num, int i, int j) {
        while (i < j) swap(num[i++], num[j--]);
    };

    void nextPermutation(string &num) {
        int N = num.size();
        if (N < 2) return;
        int i = N - 2;
        while (i >= 0 && num[i] >= num[i+1]) i--;
        if (i == -1) {
            reverse(num, 0, N - 1);
            return;
        }
        int j = N - 1;
        while (j > i && num[j] <= num[i]) j--;
        assert(j > i);
        swap(num[i], num[j]);
        reverse(num, i + 1, N - 1);
    };

    string getPermutation(int n, int k) {
        string num = "";
        for (int i = 0; i < n; i++) num.push_back('1' + i);
        for (int i = 1; i < k; i++) nextPermutation(num);
        return num;
    }
};

int main() {
    return 0;
}
