#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        int next = 0;
        int temp = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == INT_MAX - 1 || nums[i] <= 0 || nums[i] > n)
                continue;
            next = nums[i] - 1;
            while (nums[next] != INT_MAX - 1 && nums[next] > 0 && nums[next] <= n)
            {
                temp = nums[next];
                nums[next] = INT_MAX - 1;
                next = temp - 1;
            }
            nums[next] = INT_MAX - 1;
        }

        for (int i = 0; i < n; i++)
            if (nums[i] != INT_MAX - 1)
                return i + 1;
        return n + 1;
    }
};