#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        if (nums.size() < 3)
            return 0;
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 2; i < nums.size(); i++)
            for (int l = 0, r = i - 1; l < r;)
                if (nums[l] + nums[r] > nums[i])
                    ans += (r-- - l);
                else
                    l++;
        return ans;
    }
};