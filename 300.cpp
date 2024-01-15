#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int ans = 1;
        int n = nums.size();
        vector<int> record = vector<int>(n, 1);

        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j])
                {
                    record[i] = max(record[i], record[j] + 1);
                    ans = max(ans, record[i]);
                }
        return ans;
    }
};