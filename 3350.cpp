#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxIncreasingSubarrays(vector<int> &nums)
    {
        vector<int> record = vector<int>();
        int ans = INT_MIN;
        int m = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            int now = i;
            int j = i + 1;
            for (; j < nums.size() && nums[now] < nums[j]; j++, now++)
                ;
            record.push_back(j - i);
            i = j - 1;
        }
        for (int i = 0; i < record.size() - 1; i++)
        {
            m = max(m, record[i]);
            ans = max(ans, min(record[i], record[i + 1]));
        }
        ans = max(ans, max(m, record[record.size() - 1]) / 2);
        return ans;
    }
};