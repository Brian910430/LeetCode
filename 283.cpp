#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0, j = 0; i < n; i++)
            if (nums[i] == 0)
                for (j = max(i + 1, j); j < n; j++)
                    if (nums[j] != 0)
                    {
                        swap(nums[i], nums[j]);
                        break;
                    }
    }
};