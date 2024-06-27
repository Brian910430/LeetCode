#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        map<int, int> count;
        for (auto i : hand)
            count[i]++;
        for (auto it = count.begin(); it != count.end(); it++)
        {
            int n = it->first;
            while (count[n])
            {
                for (int i = 0; i < groupSize; i++)
                {
                    if (count[n + i] == 0)
                        return false;
                    count[n + i]--;
                }
            }
        }
        return true;
    }
};