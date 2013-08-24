//============================================================================
// Best Time to Buy and Sell Stock
// 
// Say you have an array for which the ith element is the price of a given 
// stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete at most 
// two transactions.
//
// Note:
// You may not engage in multiple transactions at the same time (ie, you must 
// sell the stock before you buy again).
//
//============================================================================

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int N = prices.size();
        if (N <= 1) return 0;
        int min_val = prices[0];
        vector<int> left(N, 0);
        for (int i = 1; i < N; ++i)
        {
            if (prices[i] < min_val) min_val = prices[i];
            left[i] = max(left[i-1], prices[i]-min_val);
        }
        int max_val = prices[N-1];
        vector<int> right(N, 0);
        for (int i = N-2; i >= 0; --i)
        {
            if (prices[i] > max_val) max_val = prices[i];
            right[i] = max(right[i+1], max_val-prices[i]);
        }
        int res = 0;
        for (int i = 0; i < N; ++i)
            res = max(res, left[i]+right[i]);
        return res;
    }
};


int main()
{
    return 0;
}
