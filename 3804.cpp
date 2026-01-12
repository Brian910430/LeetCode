#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int centeredSubarrays(vector<int> &nums)
    {
        int ans = 0;
        int sum = 0;
        unordered_set<int> record;

        for (int i = 0; i < nums.size(); i++)
        {
            sum = 0;
            record.clear();
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                record.insert(nums[j]);
                if (record.count(sum))
                    ans++;
            }
        }
        return ans;
    }
};