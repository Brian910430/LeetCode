#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        int left = 0;
        int right = (int)sqrt(c);

        while (left <= right)
        {
            long long current = (long long)left * left + (long long)right * right;
            if (current == c)
                return true;
            else if (current < c)
                left++;
            else
                right--;
        }
        return false;
    }
};