#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        int l = s.length();
        for (int i = 0; i < s.length(); i++)
            if (s[i] == goal[0] && s.substr(i, l - i) + s.substr(0, i) == goal)
                return true;
        return false;
    }
};