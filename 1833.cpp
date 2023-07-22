#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        int count = 0;
        int cost = 0;
        sort(costs.begin(), costs.end());
        for (auto n : costs)
        {
            if (cost + n > coins)
                break;
            else
            {
                cost += n;
                count++;
            }
        }
        return count;
    }
};
