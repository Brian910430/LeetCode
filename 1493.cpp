#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int length = 1;
        int ans = 0;
        bool flag = false;
        vector<int> ones;
        vector<int> others;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                flag = true;
                while (i + 1 < n && nums[i + 1] == 1)
                {
                    i++;
                    length++;
                }
                ones.push_back(length);
                ans = max(ans, length);
            }
            else if (flag)
            {
                while (i + 1 < n && nums[i + 1] != 1)
                {
                    i++;
                    length++;
                }
                others.push_back(length);
            }
            length = 1;
        }
        if (others.size() == 0)
        {
            if (ones.size() == 0)
                return 0;
            if (ones[0] < n)
                return ones[0];
            else
                return ones[0] - 1;
        }
        for (int i = 0; i < ones.size() - 1; i++)
            if (others[i] == 1)
                ans = max(ans, ones[i] + ones[i + 1]);
        return ans;
    }
};