#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        int ans = numBottles;

        while (numBottles >= numExchange)
        {
            int temp = 0;
            int i = 0;
            for (; temp <= numBottles; i++)
                temp += (numExchange + i);
            ans += i - 1;
            numExchange += i - 1;
            numBottles -= (temp - numExchange - i + 1);
        }
        return ans;
    }
};