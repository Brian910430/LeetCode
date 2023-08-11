#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        if (nums[0] == target)
            return 0;
        else if (nums[0] < target)
        {
            while (left < right)
            {
                int mid = (left + right + 1) / 2;
                if (nums[mid] > target || nums[mid] < target && nums[mid] < nums[0])
                    right = mid - 1;
                else if (nums[mid] < target)
                    left = mid;
                else
                    return true;
            }
        }
        else if (nums[0] > target)
        {
            while (left < right)
            {
                int mid = (left + right + 1) / 2;
                if (nums[mid] < target || nums[mid] > target && nums[mid] > nums[0])
                    left = mid;
                else if (nums[mid] > target)
                    right = mid - 1;
                else
                    return true;
            }
        }
        return -1;
    }
};