#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfPaths(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));
        dp[0][0][grid[0][0] % k] = 1;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                for (int c = 0; c < k; c++)
                {
                    if (i > 0 && dp[i - 1][j][c] > 0)
                    {
                        int mod = (c + grid[i][j]) % k;
                        dp[i][j][mod] = (dp[i][j][mod] + dp[i - 1][j][c]) % (int)(1e9 + 7);
                    }
                    if (j > 0 && dp[i][j - 1][c] > 0)
                    {
                        int mod = (c + grid[i][j]) % k;
                        dp[i][j][mod] = (dp[i][j][mod] + dp[i][j - 1][c]) % (int)(1e9 + 7);
                    }
                }
        return dp[m - 1][n - 1][0];
    }
};