#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int ans = 0;
        int now = prices[0];
        for (int i = 1; i < n; i++)
        {
            if (now > prices[i])
                now = prices[i];
            else if (ans < prices[i] - now)
                ans = prices[i] - now;
        }
        return ans;
    }
};