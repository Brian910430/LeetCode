#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < arr.size(); i++)
            map[arr[i]]++;
        for (auto i : map)
            if (i.second > arr.size() / 4)
                return i.first;
        return 0;
    }
};