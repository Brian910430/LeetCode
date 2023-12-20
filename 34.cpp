#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                int left = mid;
                int right = mid;
                while (left >= 0 && nums[left] == target)
                    left--;
                while (right < nums.size() && nums[right] == target)
                    right++;
                return {left + 1, right - 1};
            }
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
            mid = (left + right) / 2;
        }
        return {-1, -1};
    }
};