#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalMoney(int n)
    {
        int weeks = n / 7;
        int days = n % 7;
        int ans = 0;
        ans += weeks * 28;
        for (int i = 0; i < weeks; i++)
            ans += i * 7;
        for (int i = 0; i < days; i++)
            ans += (i + 1 + weeks);
        return ans;
    }
};