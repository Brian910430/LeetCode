#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        vector<int> record(cost.size() + 1, 0);
        record[cost.size() - 1] = cost[cost.size() - 1];
        for (int i = cost.size() - 2; i >= 0; i--)
            record[i] = cost[i] + min(record[i + 1], record[i + 2]);
        return min(record[0], record[1]);
    }
};