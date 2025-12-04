#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSub(string s)
    {
        int count = 0;
        int ans = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
                ans = (++count + ans) % (int)(1e9 + 7);
            else
                count = 0;
        }
        return ans;
    }
};