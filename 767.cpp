#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reorganizeString(string s)
    {
        priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>>> record;
        map<char, int> count;
        string ans = "";

        for (auto i : s)
            count[i]++;
        for (auto i : count)
            record.push({i.second, i.first});
        while (record.size() > 1)
        {
            pair<int, char> a = record.top();
            record.pop();
            pair<int, char> b = record.top();
            record.pop();
            ans += a.second;
            ans += b.second;
            if (a.first > 1)
                record.push({a.first - 1, a.second});
            if (b.first > 1)
                record.push({b.first - 1, b.second});
        }
        if (record.size() == 1)
        {
            if (record.top().first > 1)
                return "";
            ans += record.top().second;
        }
        return ans;
    }
};