#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.length();
        int m = p.length();
        vector<vector<bool>> dp = vector<vector<bool>>(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = 1;
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                if (p[j - 1] != '*')
                    dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                else
                    dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
            }
        }
        return dp[n][m];
    }
};

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        return isMatch(s, p, 0, 0);
    }

private:
    bool isMatch(string &s, string &p, int i, int j)
    {
        if (j == p.size())
            return i == s.size();

        bool match = i < s.length() && (s[i] == p[j] || p[j] == '.');
        if (j < p.length() - 1 && p[j + 1] == '*')
            return isMatch(s, p, i, j + 2) || (match && isMatch(s, p, i + 1, j));
        return match && isMatch(s, p, i + 1, j + 1);
    }
};