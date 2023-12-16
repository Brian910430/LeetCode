#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == divisor)
            return 1;
        bool isPositive = (dividend < 0 == divisor < 0);
        unsigned int ans = 0;
        unsigned int divid = abs(dividend);
        unsigned int divis = abs(divisor);
        while (divid >= divis)
        {
            int count = 0;
            while (divid > (divis << (count + 1)))
                count++;
            ans += 1 << count;
            divid -= divis << count;
        }
        if (ans == (1 << 31) && isPositive)
            return INT_MAX;
        return isPositive ? ans : -1 * ans;
    }
};

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        long long ans = (long long)dividend / divisor;
        return ans > INT_MAX ? INT_MAX : ans;
    }
};