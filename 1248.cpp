#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        vector<int> record(nums.size() + 1, 0);
        int count = 0;
        int ans = 0;

        record[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2)
                count++;
            if (count >= k)
                ans += record[count - k];
            record[count]++;
        }
        return ans;
    }
};