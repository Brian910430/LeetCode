#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries)
    {
        vector<vector<int>> diff(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < queries.size(); i++)
        {
            diff[queries[i][0]][queries[i][1]]++;
            diff[queries[i][0]][queries[i][3] + 1]--;
            diff[queries[i][2] + 1][queries[i][1]]--;
            diff[queries[i][2] + 1][queries[i][3] + 1]++;
        }
        for (int i = 0; i < n; i++)
            for (int j = 1; j < n; j++)
                diff[i][j] += diff[i][j - 1];
        for (int i = 0; i < diff.size(); i++)
            for (int j = 1; j < diff[0].size(); j++)
                diff[j][i] += diff[j - 1][i];
        diff.pop_back();
        for (int i = 0; i < diff.size(); i++)
            diff[i].pop_back();
        return diff;
    }
};