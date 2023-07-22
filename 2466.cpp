#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countGoodStrings(int &low, int &high, int &zero, int &one)
    {
        int const mod = 1e9 + 7;
        int ans = 0;
        vector<long long> record(high + 1, 0);
        record[0] = 1;

        for (int i = 0; i < high; i++)
        {
            if (record[i] && i + zero <= high)
                record[i + zero] = (record[i + zero] + record[i]) % mod;
            if (record[i] && i + one <= high)
                record[i + one] = (record[i + one] + record[i]) % mod;
        }
        for (int i = low; i <= high; i++)
            ans = (ans + record[i]) % mod;
        return ans;
    }
};