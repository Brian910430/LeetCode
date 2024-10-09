#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int ans = 0;
        int remain = 0;
        while (numBottles)
        {
            ans += numBottles;
            int temp = (remain + numBottles) % numExchange;
            numBottles = (remain + numBottles) / numExchange;
            remain = temp;
        };
        return ans;
    }
};