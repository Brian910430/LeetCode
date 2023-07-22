#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> record;
        for (auto i : nums)
            record[i]++;
        for (auto i : record)
            if (i.second == 1)
                return i.first;
    }
};