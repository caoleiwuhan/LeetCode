//============================================================================
// Given n non-negative integers representing the histogram's bar height where
// the width of each bar is 1, find the area of largest rectangle in the
// histogram.
//
// For example,
// Given height = [2,1,5,6,2,3],
// return 10.
//============================================================================

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height)
    {
        return largestRectangleArea2(height);
    }

    // based on brute-force, takes O(n^2) time
    int largestRectangleArea1(vector<int> &height)
    {
        int n = height.size();
        int area[n];
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (j >= 0 && height[j] >= height[i]) j--;
            area[i] = i-j-1;
            j = i;
            while (j < n && height[j] >= height[i]) j++;
            area[i] += (j-i-1);
            area[i] = height[i] * (area[i]+1);
            if (area[i] > res) res = area[i];
        }
        return res;
    }

    // based on stack, takes O(n) time
    int largestRectangleArea2(vector<int> &height)
    {
        int n = height.size();
        int area[n];
        stack<int> stk;
        for (int i = 0; i < n; i++) 
        {
            while (!stk.empty() && height[i] <= height[stk.top()]) stk.pop();
            int j = (stk.empty()) ? -1 : stk.top();
            // Calculating number of bars on the left
            area[i] = i - j - 1;
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();

        for (int i = n - 1; i >= 0; i--) 
        {
            while (!stk.empty() && height[i] <= height[stk.top()]) stk.pop();
            int j = (stk.empty()) ? n : stk.top();
            // Calculating number of bars on the left + right
            area[i] += (j - i - 1);
            stk.push(i);
        }

        int res = 0;
        for (int i = 0; i < n; i++) 
        {
            // Calculating height * width
            area[i] = height[i] * (area[i] + 1);
            if (area[i] > res) res = area[i];
        }
        return res;
    }
};

int main() 
{
    int x[] = {2,1,5,6,2,3};
    vector<int> height(x, x + sizeof(x)/sizeof(int));
    Solution sol;
    cout << sol.largestRectangleArea(height) << endl;
    return 0;
}
