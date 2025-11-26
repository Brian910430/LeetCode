#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {
        int ans = INT_MIN;
        vector<int> dp(nums.size() + 1, 1);
        sort(nums.begin(), nums.end());

        for (int left = 0, right = 0; right < nums.size(); right++)
        {
            while ((long long)nums[left] * nums[left] < nums[right])
                left++;
            if ((long long)nums[left] * nums[left] == nums[right])
                dp[right] = dp[left] + 1;
            ans = max(ans, dp[right]);
        }
        return ans == 1 ? -1 : ans;
    }
};