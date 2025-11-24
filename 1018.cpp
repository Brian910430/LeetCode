#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int> &nums)
    {
        vector<bool> ans = vector<bool>();
        long long num = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            num = (num * 2 + nums[i]) % 5;
            ans.push_back(num == 0 ? true : false);
        }
        return ans;
    }
};