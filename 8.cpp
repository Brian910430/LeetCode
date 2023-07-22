#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int index = 0;
        int sign = 1;
        long ans = 0;
        for (; s[index] == ' '; index++)
            ;
        if (s[index] == '+')
        {
            sign = 1;
            index++;
        }
        else if (s[index] == '-')
        {
            sign = -1;
            index++;
        }

        while (s[index] <= '9' && s[index] >= '0')
        {
            int temp = sign * (s[index] - '0');
            if (sign == 1 && (INT_MAX / 10 < ans || (INT_MAX / 10 == ans && INT_MAX % 10 < temp)))
                return INT_MAX;
            if (sign == -1 && (INT_MIN / 10 > ans || (INT_MIN / 10 == ans && INT_MIN % 10 > temp)))
                return INT_MIN;
            ans = ans * 10 + temp;
            index++;
        }
        return ans;
    }
};