#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> set1 = unordered_set<int>();
        unordered_set<int> set2 = unordered_set<int>();
        unordered_set<int> temp = unordered_set<int>();
        vector<vector<int>> ans = vector<vector<int>>(2, vector<int>());

        for (auto i : nums1)
            set1.insert(i);
        for (auto i : nums2)
            set2.insert(i);

        for (auto i : nums1)
            if (set2.count(i) == 0)
                temp.insert(i);
        for (auto i : temp)
            ans[0].push_back(i);
        temp.clear();
        for (auto i : nums2)
            if (set1.count(i) == 0)
                temp.insert(i);
        for (auto i : temp)
            ans[1].push_back(i);
        return ans;
    }
};