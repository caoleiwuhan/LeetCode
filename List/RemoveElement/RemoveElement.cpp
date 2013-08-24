//============================================================================
// Remove Element
// Given an array and a value, remove all instances of that value in place
// and return the new length.
//
// The order of elements can be changed. It doesn't matter what you leave
// beyond the new length.
//============================================================================

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0, j = 0;
        while (i < n) {
            if (A[i] != elem) {
                if (i == j) i++, j++;
                else A[j++] = A[i++];
            }
            else i++;
        }
        return j;
    }
};

int main() {
	return 0;
}
