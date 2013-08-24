//============================================================================
// Pascal's Triangle
// Given numRows, generate the first numRows of Pascal's triangle.
//
// For example, given numRows = 5,
// Return
//
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int> > generate(int numRows)
    {
        vector<vector<int> > res;
        if (numRows < 1) return res;
        res.reserve(numRows);
        res.push_back(vector<int>(1, 1));
        int m = 1;
        while (m < numRows)
        {
            vector<int> row;
            row.reserve(m+1);
            row.push_back(1);
            for (int i = 0; i < m-1; i++)
                row.push_back(res[m-1][i] + res[m-1][i+1]);
            row.push_back(1);
            res.push_back(row);
            m++;
        }
        return res;
    }
};

int main()
{
    return 0;
}
