#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        vector<int> record(31, 0);
        record[1] = 1;
        for (int i = 2; i <= n; i++)
            record[i] = record[i - 1] + record[i - 2];
        return record[n];
    }
};