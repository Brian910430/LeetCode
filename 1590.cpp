#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        unordered_map<int, int> mp;
        int ans = INT_MAX;
        int prefix = 0;
        int target = 0;
        for (int i = 0; i < nums.size(); i++)
            target = (nums[i] + target) % p;
        if (target == 0)
            return 0;

        mp[0] = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            prefix = (prefix + nums[i]) % p;
            int need = (prefix - target + p) % p;
            if (mp.count(need))
                ans = min(ans, i - mp[need]);
            mp[prefix] = i;
        }
        return ans == nums.size() ? -1 : ans;
    }
};