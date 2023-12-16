#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int left = (nums[0] - 1) * (nums[1] - 1);
        int right = (nums[nums.size() - 1] - 1) * (nums[nums.size() - 2] - 1);
        return max(left, right);
    }
};