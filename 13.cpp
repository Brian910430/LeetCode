#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> value;
        int ans = 0;
        value['I'] = 1;
        value['V'] = 5;
        value['X'] = 10;
        value['L'] = 50;
        value['C'] = 100;
        value['D'] = 500;
        value['M'] = 1000;

        for (int i = 0; i < s.length(); i++)
            if (i + 1 < s.length() && value[s[i]] < value[s[i + 1]])
                ans -= value[s[i]];
            else
                ans += value[s[i]];
        return ans;
    }
};