#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int n = nums.size();
        int sum = 0;
        int ans = 0;
        vector<int> record(n + 5, 0);
        record[0] = 1;

        for (auto num : nums)
        {
            sum += num;
            ans += sum >= goal ? record[sum - goal] : 0;
            record[sum]++;
        }
        return ans;
    }
};