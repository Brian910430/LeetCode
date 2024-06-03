#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int scoreOfString(string s)
    {
        int ans = 0;
        char temp = s[0];

        for (int i = 1; i < s.length(); i++)
        {
            ans += abs(s[i] - temp);
            temp = s[i];
        }
        return ans;
    }
};