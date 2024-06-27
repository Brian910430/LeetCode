#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        int sum = 0;

        map[0] = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int remainder = sum % k;
            if (map.find(remainder) == map.end())
                map[remainder] = i;
            else if (i - map[remainder] > 1)
                return true;
        }
        return false;
    }
};