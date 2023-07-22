#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        vector<string> ans;
        priority_queue<pair<int, string>> map;
        for (int i = 0; i < heights.size(); i++)
            map.push({heights[i], names[i]});
        while (map.size())
        {
            ans.push_back(map.top().second);
            map.pop();
        }
        return ans;
    }
};