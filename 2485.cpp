#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotInteger(int n)
    {
        int total = (1 + n) * n / 2;
        int left = 0;
        int right = n;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            int sum = (mid - 1) * mid / 2;
            int remain = total - sum - mid;
            if (sum > remain)
                right = mid - 1;
            else if (sum < remain)
                left = mid + 1;
            else
                return mid;
        }
        return -1;
    }
};