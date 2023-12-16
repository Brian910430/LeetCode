#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        unordered_map<string, int> record;

        for (auto i : paths)
        {
            record[i[0]] = 0;
            if (record.find(i[1]) == record.end())
                record[i[1]] = 1;
            else
                record[i[1]] = 0;
        }
        for (auto i : record)
            if (i.second == 1)
                return i.first;
        return "";
    }
};