#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char findKthBit(int n, int k)
    {
        int sz = 32 - __builtin_clz(n);
        if (n == 1)
            return '0';
        long long l = (pow(2, n) - 1) / 2;
        if (k <= l)
            return findKthBit(n - 1, k);
        else if (k == l + 1)
            return '1';
        else
            return findKthBit(n - 1, l * 2 + 2 - k) == '0' ? '1' : '0';
        return 0;
    }
};