#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool search(std::vector<int> &nums, int target)
    {
        if (nums.empty())
            return 0;
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return true;
            else if (nums[left] == nums[mid] && nums[mid] == nums[right])
            {
                left++;
                right--;
            }
            else if (nums[left] <= nums[mid])
            {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {
                if (target <= nums[right] && nums[mid] < target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return false;
    }
};