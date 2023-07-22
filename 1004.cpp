#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int ans = 0;
        int left = 0;
        int right = 0;

        for (; right < nums.size(); right++)
        {
            if (nums[right] == 0)
            {
                if (k > 0)
                    k--;
                else
                {
                    while (nums[left] == 1)
                        left++;
                    left++;
                }
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};