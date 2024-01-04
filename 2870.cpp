#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int ans = 0;
        unordered_map<int, int> Map;

        for (int i = 0; i < nums.size(); i++)
            Map[nums[i]]++;
        for (auto i : Map)
        {
            if (i.second == 1)
                return -1;
            ans += (i.second / 3 + (i.second % 3 > 0));
        }
        return ans;
    }
};