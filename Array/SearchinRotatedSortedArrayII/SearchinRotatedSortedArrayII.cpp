//============================================================================
// Search in Rotated Sorted Array II
//
// Follow up for "Search in Rotated Sorted Array":
// What if duplicates are allowed?
//
// Would this affect the run-time complexity? How and why?
//
// Write a function to determine if a given target is in the array.
//============================================================================

#include <iostream>
using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
        for (int i = 0; i < n; i++) {
            if (A[i] == target) return true;
        }
        return false;
    }
};

int main() {
    return 0;
}
