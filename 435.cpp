#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int edge = INT_MIN;
        int ans = 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { if(a[1] == b[1]) return a[0] < b[0]; else return a[1] < b[1]; });
        for (auto now : intervals)
        {
            if (edge <= now[0])
                edge = now[1];
            else
                ans++;
        }
        return ans;
    }
};