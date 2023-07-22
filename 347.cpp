#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> record;
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        for (auto i : nums)
            record[i]++;
        for (auto i : record)
            pq.push({i.second, i.first});
        for (auto i = 0; i < k; i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};