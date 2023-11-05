#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        int n = words.size();
        int len = 0;
        string s = "";
        vector<string> ans;
        vector<string> record;

        for (int i = 0; i < n; i++)
        {
            if (len + record.size() + words[i].size() > maxWidth)
            {
                if (record.size() == 1)
                {
                    s += record[0];
                    for (int i = 0; i < maxWidth - len; i++)
                        s += " ";
                }
                else
                {
                    for (int i = 0; i < maxWidth - len; i++)
                        record[i % (record.size() - 1)] += " ";
                    for (auto i : record)
                        s += i;
                }
                ans.push_back(s);
                record.clear();
                len = 0;
                s = "";
            }
            record.push_back(words[i]);
            len += words[i].size();
        }
        for (auto i : record)
            s += i + " ";
        s.pop_back();
        for (int i = s.length(); i < maxWidth; i++)
            s += " ";
        ans.push_back(s);
        return ans;
    }
};