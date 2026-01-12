#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        unordered_set<int> existed = unordered_set<int>();
        for (int i = 0; i < nums.size(); i++)
            if (existed.count(nums[i]))
                return nums[i];
            else
                existed.insert(nums[i]);
        return 0;
    }
};
