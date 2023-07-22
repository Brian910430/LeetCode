#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool pyramidTransition(string bottom, vector<string> &allowed)
    {
        for (auto i : allowed)
            map[i.substr(0, 2)].insert(i[2]);
        return DFS(bottom, "", 0);
    }

private:
    unordered_map<string, unordered_set<char>> map;
    bool DFS(string &now, string next, int i)
    {
        if (now.length() == 1)
            return true;
        else if (now.length() == next.length() + 1)
            return DFS(next, "", 0);
        string str = now.substr(i, 2);
        for (auto k : map[str])
            if (DFS(now, next + k, i + 1))
                return true;
        return false;
    }
};