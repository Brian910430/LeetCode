#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        unordered_map<int, int> record;
        int sum = 0;
        int ans = 0;

        record[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = (sum + nums[i]) % k;
            if (sum < 0)
                sum += k;
            if (record.find(sum) != record.end())
                ans += record[sum];
            record[sum]++;
        }
        return ans;
    }
};