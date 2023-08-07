#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.length();
        vector<bool> record(n, false);
        record[0] = true;

        for (int i = 1; i <= n; i++)
        {
            for (auto word : wordDict)
            {
                int len = word.length();
                if (i - len >= 0 && s.substr(i - len, len) == word)
                    record[i] = record[i] || record[i - len];
            }
        }
        return record[n];
    }
};