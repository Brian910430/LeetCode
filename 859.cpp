#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        if (s.length() != goal.length())
            return false;

        vector<pair<char, char>> diff;
        unordered_set<char> record;
        bool flag = false;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != goal[i])
                diff.push_back({s[i], goal[i]});
            if (record.count(s[i]))
                flag = true;
            else
                record.insert(s[i]);
        }
        if (diff.size() == 0)
            return flag;
        else if (diff.size() == 2)
            return diff[0].first == diff[1].second && diff[1].first == diff[0].second;
        else
            return false;
    }
};