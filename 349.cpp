#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        unordered_set<int> record(nums1.begin(), nums1.end());

        for (auto i : nums2)
            if (record.count(i))
            {
                ans.push_back(i);
                record.erase(i);
            }
        return ans;
    }
};