#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxUniqueSplit(string s)
    {
        unordered_set<string> record;
        return backTrack(s, 0, record);
    }

private:
    int backTrack(string s, int index, unordered_set<string> &record)
    {
        int l = s.length();
        int ans = INT_MIN;
        if (index == l)
            return record.size();
        for (int i = index; i < l; i++)
        {
            string sub = s.substr(index, i - index + 1);
            if (record.find(sub) == record.end())
            {
                record.insert(sub);
                ans = max(ans, backTrack(s, i + 1, record));
                record.erase(sub);
            }
        }
        return ans;
    }
};