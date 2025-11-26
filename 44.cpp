#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMatch(string &s, string &p)
    {
        int i = 0;
        int j = 0;
        int match = 0;
        int starIdx = -1;

        while (i < s.length())
            if (p[j] == '?' || s[i] == p[j])
                i++, j++;
            else if (p[j] == '*')
                starIdx = j, match = i, j++;
            else if (starIdx != -1)
                j = starIdx + 1, i = ++match;
            else
                return false;

        while (j < p.length() && p[j] == '*')
            j++;
        return j == p.length();
    }
};