#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int total = 0;
        int remainGas = 0, start = 0;
        int n = gas.size();

        for (int i = 0; i < n; i++)
        {
            total += (gas[i] - cost[i]);
            remainGas += (gas[i] - cost[i]);
            if (remainGas < 0)
            {
                start = i + 1;
                remainGas = 0;
            }
        }
        if (total < 0)
            return -1;
        else
            return start;
    }
};