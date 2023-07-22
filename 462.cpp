#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        int goal;
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if (n % 2)
            goal = nums[n / 2];
        else
            goal = (nums[n / 2] + nums[n / 2 - 1]) / 2;
        for (auto i : nums)
            ans += abs(i - goal);
        return ans;
    }
};