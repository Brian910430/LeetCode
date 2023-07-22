#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> step(46, 0);
        step[1] = 1;
        step[2] = 2;
        for (int i = 3; i <= n; i++)
            step[i] = step[i - 1] + step[i - 2];
        return step[n];
    }
};