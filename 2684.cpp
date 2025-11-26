#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxMoves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = INT_MIN;
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int j = m - 2; j >= 0; j--)
        {
            for (int i = 0; i < n; i++)
            {
                int maxNum = INT_MIN;
                if (i > 0 && grid[i - 1][j + 1] > grid[i][j])
                    maxNum = max(maxNum, dp[i - 1][j + 1]);
                if (grid[i][j + 1] > grid[i][j])
                    maxNum = max(maxNum, dp[i][j + 1]);
                if (i < n - 1 && grid[i + 1][j + 1] > grid[i][j])
                    maxNum = max(maxNum, dp[i + 1][j + 1]);
                if (maxNum != INT_MIN)
                    dp[i][j] = maxNum + 1;
            }
        }
        for (int i = 0; i < n; i++)
            ans = max(ans, dp[i][0]);
        return ans;
    }
};