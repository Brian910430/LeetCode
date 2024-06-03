#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        int ans = -1;
        unordered_set<int> s(nums.begin(), nums.end());

        for (auto i : nums)
            if (s.count(-i) != 0 && i > ans)
                ans = i;
        return ans;
    }
};