#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numTilings(int n)
    {
        vector<long long> record(1001, 0);
        int mod = 1e9 + 7;
        record[1] = 1;
        record[2] = 2;
        record[3] = 5;
        for (int i = 4; i <= n; i++)
            record[i] = (record[i - 1] * 2 + record[i - 3]) % mod;
        return record[n];
    }
};