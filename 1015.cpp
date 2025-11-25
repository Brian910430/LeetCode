#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestRepunitDivByK(int k)
    {
        if (k % 2 == 0 || k % 5 == 0)
            return -1;

        int ans = 0;
        int num = 0;
        while (1)
        {
            num = (num * 10 + 1) % k;
            ans++;
            if (num == 0)
                return ans;
        }
        return -1;
    }
};