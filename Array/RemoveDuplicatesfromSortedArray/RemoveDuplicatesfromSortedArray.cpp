//============================================================================
// Remove Duplicates from Sorted Array
// Given a sorted array, remove the duplicates in place such that each element
// appear only once and return the new length.
//
// Do not allocate extra space for another array, you must do this in place
// with constant memory.
//
// For example,
// Given input array A = [1,1,2],
//
// Your function should return length = 2, and A is now [1,2].
//============================================================================

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 2) return n;
        int i = 1, j = 1;
        while (i < n) {
            if (A[i-1] != A[i]) A[j++] = A[i++];
            else i++;
        }
        return j;
    }
};

int main() {
    return 0;
}
