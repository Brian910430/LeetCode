#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int ans = INT_MAX;
        vector<int> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; i++)
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        if (prefixSum[n] < target)
            return 0;

        for (int i = 0, j = 0; i < n; i++)
        {
            while (j < n && prefixSum[j] - prefixSum[i] < target)
                j++;
            while (prefixSum[j] - prefixSum[i + 1] >= target)
                i++;
            ans = min(j - i, ans);
            if (j == n)
                break;
        }
        return ans;
    }
};