#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution
{
public:
    long long minTime(vector<int> &skill, vector<int> &mana)
    {
        int n = skill.size();
        int m = mana.size();
        vector<vector<ll>> dp = vector<vector<ll>>(n + 1, vector<ll>(m + 1, 0));

        dp[0][0] = skill[0] * mana[0];
        for (int i = 1; i < n; i++)
            dp[i][0] = dp[i - 1][0] + skill[i] * mana[0];
        for (int j = 1; j < m; j++)
        {
            dp[0][j] = dp[0][j - 1] + skill[0] * mana[j];
            for (int i = 1; i < n; i++)
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + skill[i] * mana[j];
            for (int i = n - 1; i > 0; i--)
                dp[i - 1][j] = max(dp[i - 1][j], dp[i][j] - skill[i] * mana[j]);
        }
        return dp[n - 1][m - 1];
    }
};