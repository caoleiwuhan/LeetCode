//============================================================================
// Best Time to Buy and Sell Stock
//
// Say you have an array for which the ith element is the price of a given
// stock on day i.
//
// If you were only permitted to complete at most one transaction (ie, buy
// one and sell one share of the stock), design an algorithm to find the
// maximum profit.
//
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        size_t min_i = 0;
        int res = 0;
        for (size_t i = 0; i < prices.size(); i++)
        {
            if (prices[i] < prices[min_i]) min_i = i;
            int diff = prices[i] - prices[min_i];
            if (diff > res) res = diff;
        }
        return res;
    }
};

int main()
{
    return 0;
}
