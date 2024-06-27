#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        int ans = 0;
        int count = 0;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            count = max(count, nums[i]);
            ans += (count - nums[i]);
            count++;
        }
        return ans;
    }
};