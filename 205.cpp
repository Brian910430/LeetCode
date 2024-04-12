#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> m;
        int n = s.length();

        if (n != t.length())
            return false;
        for (int i = 0; i < n; i++)
        {
            if (m.find(s[i]) != m.end() && m[s[i]] != t[i])
                return false;
            m[s[i]] = t[i];
        }
        m.clear();
        for (int i = 0; i < n; i++)
        {
            if (m.find(t[i]) != m.end() && m[t[i]] != s[i])
                return false;
            m[t[i]] = s[i];
        }
        return true;
    }
};