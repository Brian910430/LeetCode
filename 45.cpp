#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int j;
        vector<int> record(n, 0);
        for (int i = 0; i < n - 1; i++)
            for (j = 1; j <= nums[i]; j++)
                if (i + j < n && (record[i + j] > record[i] + 1 || record[i + j] == 0))
                    record[i + j] = record[i] + 1;
        return record[n - 1];
    }
};