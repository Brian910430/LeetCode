#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int waysToReachTarget(int target, vector<vector<int>> &types)
    {
        mod = 1e9 + 7;
        record.resize(target + 1, vector<int>(types.size() + 1, -1));
        for (int i = 0; i < types.size(); i++)
            swap(types[i][0], types[i][1]);
        sort(types.begin(), types.end());
        return backTrack(types, target, 0);
    }

private:
    int mod;
    vector<vector<int>> record;
    int backTrack(vector<vector<int>> &types, int goal, int index)
    {
        if (goal == 0)
            return 1;
        if (goal < 0 || index >= types.size())
            return 0;
        if (record[goal][index] != -1)
            return record[goal][index];

        int result = 0;
        for (int i = 0; i <= types[index][1]; i++)
            result = (result + backTrack(types, goal - types[index][0] * i, index + 1)) % mod;
        return record[goal][index] = result;
    }
};