#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxSubarraySum(vector<int> &nums, int k)
    {
        vector<long long> minSoFar(k, LONG_LONG_MAX);
        long long ans = LONG_LONG_MIN;
        long long prefixSum = 0;
        minSoFar[k - 1] = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];
            ans = (minSoFar[i % k] == LONG_LONG_MAX && prefixSum < 0) ? ans : max(prefixSum - minSoFar[i % k], ans);
            minSoFar[i % k] = min(minSoFar[i % k], prefixSum);
        }
        return ans;
    }
};