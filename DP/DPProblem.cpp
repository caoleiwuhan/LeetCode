#include <iostream>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

/*
    匹配*和.
*/
// 递归思路
bool isMatch(const char *s, const char *p)
{
    if (*s == '\0' && *p == '\0')
        return true;
    if (*(p+1) != '*')
    {
        if (*s == *p || (*p == '.' && *s != '\0'))
        {
            return isMatch(s + 1, p + 1);
        }
    }

    while (*s == *p || (*p == '.' && *s != '\0'))
    { // 将相等的都匹配（至少一个）
        if (isMatch(s, p + 2))
            return true;
        ++s;
    }

    // 一个也不匹配
    return isMatch(s, p + 2);
}

bool isMatchDP(const char *s, const char *p)
{
    int len1 = strlen(s);
    int len2 = strlen(p);
    vector<vector<bool> > dp(len1 + 1, vector<bool>(len2 + 1, false));
    dp[0][0] = true;

    for (int i = 1; i <= len2; ++i)
    {
        if (i & 1)
            continue;
        if (dp[0][i-2] && p[i] == '*')
            dp[0][i] = true;
        else
            break;
    }
    for (int i = 1; i <= len1; ++i)
    {
        for (int j = 1; j <= len2; ++j)
        {
            if (s[i-1] == p[j-1] || p[j-1] == '.')
                dp[i][j] = dp[i-1][j-1];
            else if (p[j-1] == '*') // 如果当前为*
            {
                if ((j > 1) && dp[i][j-2])
                { // 当前的与前面一个都不用匹配
                    dp[i][j] = true;
                }
                else
                { // 要匹配了
                    if (s[i-1] == p[j-1] || p[j-1] == '.')
                    {
                        if (dp[i-1][j]) // 匹配多个
                            dp[i][j] = dp[i-1][j];
                        else if (j > 2) // 匹配一个
                            dp[i][j] = dp[i-1][j-2];
                    }
                }
            }
        }
    }
    return dp[len1][len2];
}

/*
    wildcard matching
    匹配？和*
*/
// 递归
bool isWildCardMatch(const char *s, const char *p)
{
    if (*s == '\0' && *p == '\0')
        return true;
    if (*p == '\0')
        return false;
    if (*s == '\0')
        return isWildCardMatch(s, p + 1);
    if (*s == *p || *p == '?')
        return isWildCardMatch(s + 1, p + 1);
    if (*p == '*')
    {
        if (isWildCardMatch(s + 1, p))
            return true;
    }
    // 一个也不匹配
    return isWildCardMatch(s, p + 1);
}

bool isWildCardMatchDP(const char *s, const char *p)
{
    int len1 = strlen(s);
    int len2 = strlen(p);
    vector<vector<bool> > dp(len1 + 1, vector<bool>(len2 + 1, false));
    dp[0][0] = true;
    for (int i = 0; i < len1; ++i)
    {
        for (int j = 0; j < len2; ++j)
        {
            if (i == 0 && j == 0)
                continue;
            if (i > 0 && j > 0)
            {
                if (s[i-1] == p[j-1] || p[j-1] == '?')
                {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
            if (j > 0 && p[j-1] == '*')
            {
                // 一个也不匹配
                if (dp[i][j-1])
                {
                    dp[i][j] = true;
                }
                else if (i > 0)
                {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
    }
    return dp[len1][len2];
}

/*
    minimum number of coins needed to represent an amount
    给定硬币a，总数t，找到最少的表示t的个数
*/
int minCoins(int a[], int n, int t)
{
    vector<int> f(t + 1, 0x7fffffff);
    f[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = t; j >= a[i]; --j)
        {
            if (f[j - a[i]] != 0x7fffffff)
            {
                f[j] = min(f[j], f[j-a[i]] + 1);
            }
        }
    }
    return f[t];
}

/*
    最长上升序列
*/
int LIS(int a[], int n)
{
    vector<int> f(n, 0);
    f[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (a[i] >= a[j])
            {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    return f[n-1];
}

/*
    segment string:
    给一个字典和一个长字符串，将字符串分为若干个子串，每个子串都在字典中，返回最长的划分
    f[i][j] = min(f[i][k] + f[k+1][j]) 其中i<=k<=j 且(i,k) 与 (k+1,j)都在字典中
*/
int segmentString(string str, set<string> dict)
{ // O(N^3)
    int len = str.length();
    vector<vector<int> > f(len, vector<int>(len, 0));
    for (int k = 0; k < len; ++k)
    {
        for (int i = 0; i < (len - k); ++i)
        {
            int j = i + k;
            if (dict.find(str.substr(i, k + 1)) != dict.end())
            {
                f[i][j] = 1;
            }
            for (int t = i; t < j; ++t)
            {
                if (f[i][t] && f[t+1][j])
                {
                    f[i][j] = max(f[i][j], f[i][t] + f[t+1][j]);
                }
            }
        }
    }

    return f[0][len-1];
}
/*
    套用的模型不同，复杂度不一样啊
    用矩阵连乘积：O(N^3)
    用背包或者最长递增序列：O(N^2)
*/
int segmentString2(string str, set<string> dict)
{
    int len = str.length();
    vector<int> f(len, 0);
    for (int i = 0; i < len; ++i)
    {
        for (int j = i-1; j >= 0; --j)
        {
            if (dict.find(str.substr(j + 1, i)) != dict.end() &&
                f[j])
            {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    return f[len - 1];
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
