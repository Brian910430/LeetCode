#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        int ans = 0;
        int left = 0;
        int right = nums.size() - 1;
        sort(nums.begin(), nums.end());
        while (left < right)
        {
            if (nums[left] + nums[right] < k)
                left++;
            else if (nums[left] + nums[right] > k)
                right--;
            else
            {
                left++;
                right--;
                ans++;
            }
        }
        return ans;
    }
};