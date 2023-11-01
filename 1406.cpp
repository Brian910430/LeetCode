#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string stoneGameIII(vector<int> &stoneValue)
    {
        int n = stoneValue.size();
        int res = 0;
        dp.resize(2, vector<int>(n, -1));
        res = backTrack(0, stoneValue, 0);
        if (res > 0)
            return "Alice";
        else if (res < 0)
            return "Bob";
        else
            return "Tie";
    }

private:
    vector<vector<int>> dp;
    int backTrack(int player, vector<int> &stoneValue, int index)
    {
        int n = stoneValue.size();
        if (index >= n)
            return 0;
        if (dp[player][index] != -1)
            return dp[player][index];
        if (player)
        {
            int minScore = INT_MAX;
            int score = 0;
            for (int i = index; i < min(n, index + 3); i++)
            {
                score += stoneValue[i];
                minScore = min(minScore, backTrack(0, stoneValue, i + 1) - score);
            }
            dp[player][index] = minScore;
            return minScore;
        }
        else
        {
            int maxScore = INT_MIN;
            int score = 0;
            for (int i = index; i < min(n, index + 3); i++)
            {
                score += stoneValue[i];
                maxScore = max(maxScore, score + backTrack(1, stoneValue, i + 1));
            }
            dp[player][index] = maxScore;
            return maxScore;
        }
    }
};