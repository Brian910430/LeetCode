#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int n = colors.length();
        int ans = 0;

        for (int i = 0, j = 0; i < n && j < n; i = j)
        {
            int total = 0;
            int Max = INT_MIN;
            while (j < n && colors[i] == colors[j])
            {
                total += neededTime[j];
                Max = max(Max, neededTime[j]);
                j++;
            }
            ans += total - Max;
        }
        return ans;
    }
};