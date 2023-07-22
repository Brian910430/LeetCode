#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x <= 1)
            return x;

        int left = 0;
        int right = x;
        int mid;
        while (left < right)
        {
            mid = (left + right) / 2;
            if ((long long)mid * mid > x)
                right = mid;
            else if ((long long)mid * mid < x)
                left = mid + 1;
            else
                return mid;
        }
        return right - 1;
    }
};