#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> record(n + 5, 0);
        for (int i = n - 1; i >= 0; i--)
            record[i] = nums[i] + max(record[i + 2], record[i + 3]);
        return max(record[0], record[1]);
    }
};