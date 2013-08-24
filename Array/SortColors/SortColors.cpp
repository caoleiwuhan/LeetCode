//============================================================================
// Sort Colors
// Given an array with n objects colored red, white or blue, sort them so that
// objects of the same color are adjacent, with the colors in the order red,
// white and blue.
//
// Here, we will use the integers 0, 1, and 2 to represent the color red,
// white, and blue respectively.
//
// Note:
// You are not suppose to use the library's sort function for this problem.
//
// Follow up:
// A rather straight forward solution is a two-pass algorithm using counting
// sort.
// First, iterate the array counting number of 0's, 1's, and 2's, then
// overwrite array with total number of 0's, then 1's and followed by 2's.
//
// Could you come up with an one-pass algorithm using only constant space?
//============================================================================

#include <iostream>
using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        int low = 0,mid = 0,high = n - 1;
        if(n <= 1) return;
        while (mid <= high) {
            if (A[mid] == 0) {
                A[mid++] = A[low];
                A[low++] = 0;
            }
            else if(A[mid] == 1) {
                mid++;
            }
            else if (A[mid] == 2) {
                A[mid] = A[high];
                A[high--] = 2;
            }
        }
    }
};

int main() {
    return 0;
}
