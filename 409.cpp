#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> dict;
        int ans = 0;

        for (auto i : s)
            dict[i]++;
        for (auto i : dict)
            ans += i.second / 2;
        return min(ans * 2 + 1, (int)s.length());
    }
};