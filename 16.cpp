#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int ans;
        int dis = INT_MAX;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            int l = i + 1;
            int r = n - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(target - sum) < dis)
                {
                    ans = sum;
                    dis = abs(target - sum);
                }
                if (sum < target)
                    l++;
                else
                    r--;
            }
        }
        return ans;
    }
};