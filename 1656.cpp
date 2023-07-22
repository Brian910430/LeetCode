#include <bits/stdc++.h>
using namespace std;

class OrderedStream
{
public:
    OrderedStream(int n)
    {
        pointer = 1;
    }

    vector<string> insert(int idKey, string value)
    {
        vector<string> ans;
        map[idKey] = value;
        while (map[pointer] != "")
            ans.push_back(map[pointer++]);
        return ans;
    }

private:
    int pointer;
    unordered_map<int, string> map;
};