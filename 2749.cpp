#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int makeTheIntegerZero(int num1, int num2)
    {
        long long num_1 = num1;
        long long num_2 = num2;
        for (int i = 1; i <= 60; i++)
        {
            num_1 -= num_2;
            if (num_1 < i)
                return -1;
            if (countBits(num_1) <= i)
                return i;
        }
        return -1;
    }

private:
    int countBits(long long num)
    {
        if (num < 0)
            return INT_MAX;
        int count = 0;
        while (num)
        {
            count += num & 1;
            num >>= 1;
        }
        return count;
    }
};