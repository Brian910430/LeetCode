#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minEnd(int n, int x)
    {
        long long index = 1;
        long long ans = x;
        n = n - 1;
        while (n > 0)
        {
            if ((index & ans) == 0)
            {
                ans = n & 1 > 0 ? ans | index : ans;
                n >>= 1;
            }
            index <<= 1;
        }
        return ans;
    }
};