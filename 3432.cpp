#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPartitions(vector<int> &nums)
    {
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
            count += nums[i];
        return count % 2 == 0 ? nums.size() - 1 : 0;
    }
};