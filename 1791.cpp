#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        unordered_set<int> s;
        for (auto i : edges)
        {
            if (s.count(i[0]))
                return i[0];
            if (s.count(i[1]))
                return i[1];
            s.insert(i[0]);
            s.insert(i[1]);
        }
        return -1;
    }
};