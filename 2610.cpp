#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        vector<vector<int>> ans;
        for (auto i : nums)
            Map[i]++;
        for (auto now : Map)
        {
            while (ans.size() < now.second)
                ans.push_back(vector<int>());
            for (int i = 0; i < now.second; i++)
                ans[i].push_back(now.first);
        }
        return ans;
    }

private:
    unordered_map<int, int> Map;
};