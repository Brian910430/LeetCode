#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        if (k == 0) return 1;
        vector<int> bitcCount(32, 0);
        int left = 0;
        int right = 0;
        int sum = 0;
        int ans = INT_MAX;

        while (right < nums.size())
        {
            while (sum < k && right < nums.size())
            {
                sum |= nums[right];
                for (int i = 0, num = nums[right]; i < 32; i++, num >>= 1)
                    bitcCount[i] += (num & 1);
                right++;
            }

            while (sum >= k && left < right)
            {
                if (sum >= k)
                    ans = min(ans, right - left);
                for (int i = 0, num = nums[left]; i < 32; i++, num >>= 1)
                {
                    bitcCount[i] -= (num & 1);
                    if (bitcCount[i] == 0)
                        sum &= ~(1 << i);
                }
                left++;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};