#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countAsterisks(string s)
    {
        int ans = 0;
        bool count = true;
        for (int i = 0; i < s.length(); i++)
        {
            if (count)
            {
                if (s[i] == '*')
                    ans++;
                else if (s[i] == '|')
                    count = false;
            }
            else
            {
                if (s[i] == '|')
                    count = true;
            }
        }
        return ans;
    }
};