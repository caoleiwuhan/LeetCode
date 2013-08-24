//============================================================================
// ZigZag Conversion
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given
// number of rows like this: (you may want to display this pattern in a fixed
// font for better legibility)
//
// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:
//
// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
//============================================================================

#include <iostream>
using namespace std;

class Solution
{
public:
    string convert(string s, int nRows)
    {
        if (nRows < 2) return s;
        int N = s.size();
        int L = 2 * (nRows - 1); // provide offset
        string res;
        res.clear();
        for (int i = 0; i < N; i += L)
        {
            res.push_back(s[i]);
        }
        for (int i = 1; i < nRows - 1; i++)
        {
            for (int j = i; j < N; j += L)
            {
                res.push_back(s[j]);
                // j - i: provide offset L for each row
                // L - i: provide reverse for each column
                int k = (j - i) + (L - i);
                if (k < N) res.push_back(s[k]);
            }
        }
        for (int i = nRows - 1; i < N; i += L)
        {
            res.push_back(s[i]);
        }
        return res;
    }
};

int main()
{
    return 0;
}
