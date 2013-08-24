//============================================================================
// Best Time to Buy and Sell Stock II
//
// Say you have an array for which the ith element is the price of a given 
// stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete as many 
// transactions as you like (ie, buy one and sell one share of the stock 
// multiple times). However, you may not engage in multiple transactions at 
// the same time (ie, you must sell the stock before you buy again).
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int res = 0;
        for (size_t i = 1; i < prices.size(); i++)
            if (prices[i] > prices[i-1])
                res += (prices[i] - prices[i-1]);
        return res;
    }
};

int main()
{
    return 0;
}
