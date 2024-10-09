#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwaps(string s)
    {
        stack<char> record;
        for (auto i : s)
        {
            if (i == '[')
                record.push(i);
            else if (record.size())
                record.pop();
        }
        return (record.size() + 1) / 2;
    }
};