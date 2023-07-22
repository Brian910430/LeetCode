#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char slowestKey(vector<int> &releaseTimes, string keysPressed)
    {
        int n = releaseTimes.size();
        int time = releaseTimes[0];
        char ans = keysPressed[0];
        for (int i = n - 1; i > 0; i--)
        {
            releaseTimes[i] -= releaseTimes[i - 1];
            if (releaseTimes[i] > time || (releaseTimes[i] == time && keysPressed[i] > ans))
            {
                ans = keysPressed[i];
                time = releaseTimes[i];
            }
        }
        return ans;
    }
};