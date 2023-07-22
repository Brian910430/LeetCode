#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int passThePillow(int n, int time)
    {
        int p = n * 2 - 2;
        time %= p;
        if (time >= n)
            return p - time + 1;
        else
            return time + 1;
    }
};