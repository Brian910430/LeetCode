#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxRunTime(int n, vector<int> &batteries)
    {
        long long left = 1;
        long long right = LONG_LONG_MAX;
        long long middle;

        while (left < right)
        {
            middle = left + (right - left) / 2;
            long long total = 0;
            for (auto battery : batteries)
                total += min((long long)battery, middle);
            if (total / middle >= n)
                left = middle + 1;
            else
                right = middle;
        }
        return left - 1;
    }
};