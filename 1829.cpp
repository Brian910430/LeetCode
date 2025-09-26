#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
    {
        vector<int> ans = vector<int>(nums.size(), 0);
        int now = pow(2, maximumBit) - 1;
        for (int i = 0; i < nums.size(); i++)
        {
            now ^= nums[i];
            ans[nums.size() - 1 - i] = now;
        }
        return ans;
    }
};