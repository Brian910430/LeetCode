#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        if (k > nums[0])
            return -1;
        unordered_set<int> s;
        for (auto i : nums)
            s.insert(i);
        return nums[0] == k ? s.size() - 1 : s.size();
    }
};