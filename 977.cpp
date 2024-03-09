#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        int index = n - 1;
        int left = 0;
        int right = n - 1;
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
            nums[i] *= nums[i];
        while (left <= right)
            ans[index--] = nums[left] > nums[right] ? nums[left++] : nums[right--];
        return ans;
    }
};