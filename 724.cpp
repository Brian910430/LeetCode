#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefixSum = vector<int>(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        for (int i = 0; i < n; i++)
            if (prefixSum[i] == prefixSum[n] - prefixSum[i + 1])
                return i;
        return -1;
    }
};