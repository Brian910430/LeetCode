#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size();
        int i;
        while (left < right)
        {
            i = (left + right) / 2;
            if (nums[i] == target)
                return i;
            else if (nums[i] < target)
                left = i + 1;
            else
                right = i;
        }
        return left;
    }
};