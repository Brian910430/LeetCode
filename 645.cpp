#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size();
        unordered_set<int> s;
        vector<int> ans;
        for (int i = 1; i <= n; i++)
            s.insert(i);
        for (int i = 0; i < n; i++)
            if (s.count(nums[i]))
                s.erase(nums[i]);
            else
                ans.push_back(nums[i]);
        ans.push_back(*s.begin());
        return ans;
    }
};