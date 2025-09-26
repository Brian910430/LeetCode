#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findClosest(int x, int y, int z)
    {
        int dis1 = abs(x - z);
        int dis2 = abs(y - z);
        if (dis1 < dis2)
            return 1;
        if (dis1 > dis2)
            return 2;
        return 0;
    }
};