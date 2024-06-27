#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        multiset<int> record;
        int ans = INT_MIN;

        for (int right = 0, left = 0; right < nums.size(); right++)
        {
            record.insert(nums[right]);
            while (*record.rbegin() - *record.begin() > limit)
                record.erase(record.find(nums[left++]));
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};