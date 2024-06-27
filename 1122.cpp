#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        map<int, int> record;
        vector<int> ans;

        for (auto i : arr1)
            record[i]++;
        for (auto i : arr2)
            if (record.find(i) != record.end())
            {
                for (int j = 0; j < record[i]; j++)
                    ans.push_back(i);
                record[i] = 0;
            }
        for (auto i : record)
            if (i.second)
                for (int j = 0; j < i.second; j++)
                    ans.push_back(i.first);
        return ans;
    }
};