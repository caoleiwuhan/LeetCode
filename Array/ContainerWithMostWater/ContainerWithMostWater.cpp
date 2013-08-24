//============================================================================
// Given n non-negative integers a1, a2, ..., an, where each represents a
// point at coordinate (i, ai). n vertical lines are drawn such that the two
// endpoints of line i is at (i, ai) and (i, 0). Find two lines, which
// together with x-axis forms a container, such that the container contains
// the most water.
//
// Note: You may not slant the container.
//============================================================================

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int i = 0;
        int j = height.size() - 1;
        int max = 0;
        while (i < j) {
            int h = (height[i] < height[j]) ? height[i] : height[j];
            int res = h * (j - i);
            if (res > max) max = res;
            if (height[i] <= height[j]) {
                i++;
                while (height[i] < h && i < j) i++;
            }
            else {
                j--;
                while (height[j] < h && i < j) j--;
            }
        }
        return max;
    }
};

int main() {
    return 0;
}
