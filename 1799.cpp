#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int> &nums)
    {
        n = nums.size();
        GCD.resize(n, vector<int>(n, 0));
        dp.resize(1 << n, -1);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                GCD[i][j] = __gcd(nums[i], nums[j]);
                GCD[j][i] = GCD[i][j];
            }
        }
        return backTrack(1, 0);
    }

private:
    vector<vector<int>> GCD;
    vector<int> dp;
    int n;
    int backTrack(int time, int mask)
    {
        int MaxScore = 0;
        if (dp[mask] != -1)
            return dp[mask];
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
                continue;
            for (int j = i + 1; j < n; j++)
            {
                if (mask & (1 << j))
                    continue;
                int score = time * GCD[i][j] + backTrack(time + 1, mask | 1 << i | 1 << j);
                MaxScore = max(MaxScore, score);
            }
        }
        dp[mask] = MaxScore;
        return MaxScore;
    }
};