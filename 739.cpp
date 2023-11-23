#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        stack<pair<int, int>> record;
        vector<int> ans(n, 0);
        record.push({temperatures[0], 0});

        for (int i = 1; i < n; i++)
        {
            while (record.size() && record.top().first < temperatures[i])
            {
                auto now = record.top();
                record.pop();
                ans[now.second] = i - now.second;
            }
            record.push({temperatures[i], i});
        }
        return ans;
    }
};