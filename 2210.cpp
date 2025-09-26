#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countHillValley(vector<int> &nums)
    {
        int ans = 0;
        int status = -1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
                continue;
            else if (status == -1)
                status = nums[i] > nums[i - 1];
            else if (status == 1 && nums[i] < nums[i - 1])
            {
                status = 0;
                ans++;
            }
            else if (status == 0 && nums[i] > nums[i - 1])
            {
                status = 1;
                ans++;
            }
        }
        return ans;
    }
};