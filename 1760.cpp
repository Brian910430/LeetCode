#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool possible(vector<int> &nums, int mid, int maxOperations)
    {
        int count = 0;
        for (auto i : nums)
        {
            if (i < mid)
                ;
            else if (i % mid == 0)
                count += (i / mid - 1);
            else
                count += i / mid;
        }
        return count <= maxOperations;
    }

    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int ans = 0;
        int left = 1;
        int right;
        int mid;
        for (auto i : nums)
            right = max(right, i);
        ans = right;

        while (left < right)
        {
            mid = (left + right) / 2;
            if (possible(nums, mid, maxOperations))
            {
                ans = mid;
                right = mid;
            }
            else
                left = mid + 1;
        }
        return ans;
    }
};