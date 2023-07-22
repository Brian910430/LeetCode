#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int semiOrderedPermutation(vector<int> &nums)
    {
        int ans = 0;
        int left = 0;
        int right = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
                left = i;
            if (nums[i] == n)
                right = i;
        }
        ans = left + n - 1 - right;
        if (left > right)
            ans--;
        return ans;
    }
};