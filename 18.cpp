#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans = vector<vector<int>>();
        sort(nums.begin(), nums.end(), less<int>());
        if (nums.size() < 4)
            return ans;

        for (int i = 0; i < nums.size() - 3; i++)
        {
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                long long goal = (long long)target - nums[i] - nums[j];
                int left = j + 1, right = nums.size() - 1;
                while (left < right)
                {
                    if (goal > nums[left] + nums[right])
                        left++;
                    else if (goal < nums[left] + nums[right])
                        right--;
                    else
                    {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        int leftVal = nums[left], rightVal = nums[right];
                        while (left < right && nums[left] == leftVal)
                            left++;
                        while (left < right && nums[right] == rightVal)
                            right--;
                    }
                }
                while (j < nums.size() - 1 && nums[j] == nums[j + 1])
                    j++;
            }
            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
                i++;
        }
        return ans;
    }
};