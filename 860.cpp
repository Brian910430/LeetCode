#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int fives = 0;
        int tens = 0;
        for (auto i : bills)
        {
            if (i == 5)
                fives++;
            else if (i == 10)
            {
                fives--;
                tens++;
            }
            else
            {
                fives -= (tens > 0 ? 1 : 3);
                tens -= (tens > 0 ? 1 : 0);
            }
            if (fives < 0)
                return false;
        }
        return true;
    }
};