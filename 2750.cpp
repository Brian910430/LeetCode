#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfGoodSubarraySplits(vector<int> &nums)
    {
        long long ans = 1;
        int mod = 1e9 + 7;
        vector<int> record = vector<int>();
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == 1)
                record.push_back(i);

        if (record.size() == 0)
            return 0;
        if (record.size() == 1)
            return 1;
        for (int i = 1; i < record.size(); i++)
            ans = (ans * (record[i] - record[i - 1])) % mod;
        return ans;
    }
};