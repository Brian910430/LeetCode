#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> dp(m + 1, 0);
        for (int i = 0; i < n; i++)
        {
            int previous = 0;
            int current = 0;
            for (int j = 0; j < m; j++)
            {
                current = dp[j + 1];
                if (nums1[i] == nums2[j])
                    dp[j + 1] = previous + 1;
                else
                    dp[j + 1] = max(dp[j], current);
                previous = current;
            }
        }
        return dp[m];
    }
};