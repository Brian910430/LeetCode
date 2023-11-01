#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {
        int l = cuts.size();
        dp.resize(l + 2, vector<int>(l + 2, INT_MAX));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end(), less<int>());
        return backTrack(0, l + 1, cuts);
    }

private:
    vector<vector<int>> dp;
    int backTrack(int begin, int end, vector<int> &cuts)
    {
        if (begin + 1 == end)
            return 0;
        if (dp[begin][end] != INT_MAX)
            return dp[begin][end];
        int minCost = INT_MAX;
        for (int i = begin + 1; i < end; i++)
            minCost = min(minCost, backTrack(begin, i, cuts) + backTrack(i, end, cuts) + cuts[end] - cuts[begin]);
        dp[begin][end] = minCost;
        return minCost;
    }
};