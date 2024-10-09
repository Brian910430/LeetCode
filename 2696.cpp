#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minLength(string s)
    {
        stack<char> record;
        for (int i = 0; i < s.length(); i++)
        {
            if (record.size() && (record.top() == 'A' && s[i] == 'B' || record.top() == 'C' && s[i] == 'D'))
                record.pop();
            else
                record.push(s[i]);
        }
        return record.size();
    }
};