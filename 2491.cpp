#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        unordered_map<int, int> mp;
        long long ans = 0;
        int n = skill.size() / 2;
        int sum = 0;
        for (int i = 0; i < skill.size(); i++)
        {
            sum += skill[i];
            mp[skill[i]]++;
        }
        sum /= n;

        for (auto i : mp)
        {
            if (i.second == 0)
                continue;
            int required = sum - i.first;
            if (required == i.first)
                ans += ((long long)i.first * required * mp[i.first] / 2);
            else
            {
                if (mp[required] != mp[i.first])
                    return -1;
                ans += ((long long)i.first * required * mp[i.first]);
            }
            mp[i.first] = 0;
            mp[required] = 0;
        }
        return ans;
    }
};