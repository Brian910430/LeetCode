#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasIncreasingSubarrays(vector<int> &nums, int k)
    {
        vector<int> record = vector<int>();
        for (int i = 0; i < nums.size(); i++)
        {
            int now = i;
            int j = i + 1;
            for (; j < nums.size() && nums[now] < nums[j]; j++, now++)
                ;
            record.push_back(j - i);
            i = j - 1;
        }
        for (int i = 0; i < record.size(); i++)
        {
            if (record[i] >= k * 2)
                return true;
            if (record[i] >= k && (i + 1 < record.size() ? record[i + 1] >= k : false))
                return true;
        }
        return false;
    }
};