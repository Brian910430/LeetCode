#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {
        unordered_map<int, int> record;
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                record[nums[i] * nums[j]]++;

        for (auto i : record)
            if (i.second >= 2)
                ans += (i.second * (i.second - 1)) / 2;
        return ans *= 8;
    }
};