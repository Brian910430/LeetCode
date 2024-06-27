#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        long long now = 1;
        int index = 0;
        int ans = 0;

        while (now <= n)
        {
            if (index < nums.size() && nums[index] <= now)
            {
                now += nums[index];
                index++;
            }
            else
            {
                now *= 2;
                ans++;
            }
        }
        return ans;
    }
};