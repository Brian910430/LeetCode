#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSumDivThree(vector<int> &nums)
    {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(3, 0));
        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < 3; j++)
            {
                int now = (dp[i][j] + nums[i]) % 3;
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                dp[i + 1][now] = max(dp[i + 1][now], dp[i][j] + nums[i]);
            }
        return dp[nums.size()][0];
    }
};