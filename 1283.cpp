#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int left = 1;
        int right = INT_MAX;
        int sum = 0;
        int mid;

        mid = left + (right - left) / 2;
        while (left <= right)
        {
            sum = 0;
            for (auto i : nums)
                sum += (i / mid + (i % mid > 0));

            if (sum <= threshold)
                right = mid - 1;
            else
                left = mid + 1;
            mid = left + (right - left) / 2;
        }
        return mid;
    }
};