#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimizeMax(vector<int> &nums, int p)
    {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums[nums.size() - 1] - nums[0];
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (check(nums, p, mid))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }

private:
    bool check(vector<int> &nums, int p, int mid)
    {
        for (int i = 0; i < nums.size() - 1 && p > 0;)
        {
            if (nums[i + 1] - nums[i] <= mid)
            {
                p--;
                i += 2;
            }
            else
                i++;
        }
        return p <= 0;
    }
};