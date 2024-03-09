#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        vector<int> record(105, 0);
        int ans = 0;
        int max;

        for (int i = 0; i < nums.size(); i++)
            record[nums[i]]++;
        sort(record.begin(), record.end(), greater<int>());
        max = record[0];
        for (int i = 0; i < record.size(); i++)
            if (record[i] != max)
            {
                ans = max * i;
                break;
            }
        return ans;
    }
};