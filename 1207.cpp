#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> map1;
        unordered_map<int, int> map2;
        for (auto i : arr)
            map1[i]++;
        for (auto i : map1)
            if (map2[i.second] == 0)
                map2[i.second] = 1;
            else
                return false;
        return true;
    }
};