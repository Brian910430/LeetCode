#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> avoidFlood(vector<int> &rains)
    {
        unordered_map<int, int> fullLake = unordered_map<int, int>();
        vector<int> ans = vector<int>(rains.size(), -1);
        vector<int> dry = vector<int>();

        for (int i = 0; i < rains.size(); i++)
        {
            if (rains[i] == 0)
                dry.push_back(i);
            else
            {
                if (fullLake.find(rains[i]) != fullLake.end())
                {
                    auto iter = lower_bound(dry.begin(), dry.end(), fullLake[rains[i]]);
                    if (iter == dry.end())
                        return {};
                    ans[*iter] = rains[i];
                    dry.erase(iter);
                }
                fullLake[rains[i]] = i;
            }
        }
        for (auto i : dry)
            ans[i] = 30;
        return ans;
    }
};