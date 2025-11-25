#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0, j = 0, ans = 0;
        vector<int> leftMin = vector<int>(n, INT_MAX);
        vector<int> rightMax = vector<int>(n, INT_MIN);

        leftMin[0] = nums[0];
        rightMax[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++)
            leftMin[i] = min(leftMin[i - 1], nums[i]);
        for (int i = n - 2; i >= 0; i--)
            rightMax[i] = max(rightMax[i + 1], nums[i]);

        while (i < n && j < n)
        {
            if (leftMin[i] <= rightMax[j])
            {
                ans = max(ans, j - i);
                j++;
            }
            else
                i++;
        }
        return ans;
    }
};