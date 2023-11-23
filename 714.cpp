#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int buy = INT_MIN;
        int money = 0;

        for (int price : prices)
        {
            buy = max(buy, money - price);
            money = max(money, buy + price - fee);
        }
        return money;
    }
};