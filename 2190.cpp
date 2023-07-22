#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mostFrequent(vector<int> &nums, int key)
    {
        unordered_map<int, int> times;
        int count = INT_MIN;
        int ans;
        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] == key)
                times[nums[i + 1]]++;

        for (auto i : times)
            if (i.second > count)
            {
                count = i.second;
                ans = i.first;
            }
        return ans;
    }
};