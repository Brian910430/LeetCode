#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubseq(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        int left = 0;
        int right = n - 1;
        const int mod = 1e9 + 7;
        vector<int> pow = vector<int>(n + 1, 1);

        for (int i = 1; i < n + 1; i++)
            pow[i] = (pow[i - 1] * 2) % mod;

        while (left <= right)
        {
            if (nums[left] + nums[right] > target)
                right--;
            else
            {
                ans = (ans + pow[right - left]) % mod;
                left++;
            }
        }
        return ans;
    }
};