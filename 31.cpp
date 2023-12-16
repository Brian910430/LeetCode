#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        if (nums.size() < 2)
            return;

        for (int index = nums.size() - 1; index > 0; index--)
        {
            if (nums[index - 1] <= nums[index])
                continue;
            int now = INT_MAX;
            int replace = -1;
            for (int i = index; i < nums.size(); i++)
                if (nums[i] > nums[index - 1] && now > nums[i])
                {
                    now = nums[i];
                    replace = i;
                }
            swap(nums[index - 1], nums[replace]);
            sort(nums.begin() + index, nums.end());
            return;
        }
        sort(nums.begin(), nums.end());
    }
};