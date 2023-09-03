#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        vector<int> record(n, 0);
        set<pair<int, int>> roadSet;
        int maxRank = INT_MIN;

        for (auto i : roads)
        {
            record[i[0]]++;
            record[i[1]]++;
            roadSet.insert({i[0], i[1]});
        }
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (roadSet.find({i, j}) != roadSet.end() || roadSet.find({j, i}) != roadSet.end())
                    maxRank = max(maxRank, record[i] + record[j] - 1);
                else
                    maxRank = max(maxRank, record[i] + record[j]);
            }
        }
        return maxRank;
    }
};