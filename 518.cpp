#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        if (amount == 0)
            return 1;
        vector<int> dp(amount + 5, 0);
        dp[0] = 1;
        for (auto coin : coins)
            for (int i = 0; i < amount; i++)
                if (i + coin <= amount)
                    dp[i + coin] += dp[i];
        return dp[amount];
    }
};