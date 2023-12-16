#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> record;
        for (auto i : s)
            record[i]++;
        for (auto i : t)
            record[i]--;
        for (auto i : record)
            if (i.second != 0)
                return false;
        return true;
    }
};