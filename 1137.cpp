#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int tribonacci(int n)
    {
        vector<int> record(38);
        record[0] = 0;
        record[1] = 1;
        record[2] = 1;
        for (int i = 3; i <= n; i++)
            record[i] = record[i - 1] + record[i - 2] + record[i - 3];
        return record[n];
    }
};