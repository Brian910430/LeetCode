#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int ans = 0;
        int last;
        vector<int> laser = vector<int>(bank.size(), 0);

        for (int i = 0; i < bank.size(); i++)
            for (auto c : bank[i])
                laser[i] += (c == '1');
        last = laser[0];
        for (int i = 1; i < laser.size(); i++)
        {
            if (laser[i] != 0)
            {
                ans += last * laser[i];
                last = laser[i];
            }
        }
        return ans;
    }
};