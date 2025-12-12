#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findSmallestInteger(vector<int> &nums, int value)
    {
        vector<int> remainder = vector<int>(value, 0);
        int m = INT_MAX;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                nums[i] += -1 * (nums[i] / value - 1) * value;
            remainder[nums[i] % value]++;
        }
        for (int i = 0; i < remainder.size(); i++)
            if (m > remainder[i])
            {
                m = remainder[i];
                ans = i;
            }
        return m * value + ans;
    }
};