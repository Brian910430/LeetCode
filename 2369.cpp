#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validPartition(vector<int> &nums)
    {
        dp.resize(nums.size() + 5, -1);
        return partition(nums, 0);
    }

private:
    vector<int> dp;
    bool partition(vector<int> &nums, int i)
    {
        if (i > nums.size())
            return false;
        if (i == nums.size())
            return true;
        if (dp[i] != -1)
            return dp[i];
        if (i + 1 <= nums.size() - 1 && nums[i] == nums[i + 1])
        {
            dp[i] = (partition(nums, i + 2) || i + 2 <= nums.size() - 1 && nums[i] == nums[i + 2] && partition(nums, i + 3));
            return dp[i];
        }
        if (i + 1 <= nums.size() - 1 && nums[i] == nums[i + 1] - 1 && i + 2 <= nums.size() - 1 && nums[i + 1] == nums[i + 2] - 1)
        {
            dp[i] = partition(nums, i + 3);
            return dp[i];
        }
        return false;
    }
};