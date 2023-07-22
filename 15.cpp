#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans = vector<vector<int>>();
        int n = nums.size();

        for (int i = 0; nums[i] <= 0 && i < n - 2; i++)
        {
            int l = i + 1;
            int r = n - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0)
                    r--;
                else if (sum < 0)
                    l++;
                else
                {
                    vector<int> temp = {nums[i], nums[l], nums[r]};
                    ans.push_back(temp);
                    int left = nums[l], right = nums[r];
                    while (l < r && nums[l] == left)
                        l++;
                    while (l < r && nums[r] == right)
                        r--;
                }
            }
            while (i < n - 2 && nums[i] == nums[i + 1])
                i++;
        }
        return ans;
    }
};