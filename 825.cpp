#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numFriendRequests(vector<int> &ages)
    {
        sort(ages.begin(), ages.end());
        int ans = 0;
        int n = ages.size();
        int pointer = 0;
        for (int i = 1; i < n; i++)
        {
            for (; pointer < i; pointer++)
                if ((ages[pointer] - 7) * 2 > ages[i])
                    break;
            ans += (i - pointer);
            for (int j = i - 1; j >= 0 && ages[j] > 14; j--)
                if (ages[j] == ages[i])
                    ans++;
                else
                    break;
        }
        return ans;
    }
};