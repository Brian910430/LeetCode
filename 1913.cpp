#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        int fir_max = INT_MIN, sec_max = INT_MIN;
        int fir_min = INT_MAX, sec_min = INT_MAX;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (fir_max < nums[i])
            {
                sec_max = fir_max;
                fir_max = nums[i];
            }
            else if (sec_max < nums[i])
                sec_max = nums[i];

            if (fir_min > nums[i])
            {
                sec_min = fir_min;
                fir_min = nums[i];
            }
            else if (sec_min > nums[i])
                sec_min = nums[i];
        }
        return fir_max * sec_max - fir_min * sec_min;
    }
};