#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumReplacement(vector<int> &nums)
    {
        long long ans = 0;
        int n = nums.size();
        int last = nums[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] > last)
            {
                int temp = nums[i] / last + (nums[i] % last != 0);
                last = nums[i] / temp;
                ans += temp - 1;
            }
            else
                last = nums[i];
        }
        return ans;
    }
};