#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numMusicPlaylists(int n, int goal, int k)
    {
        record.resize(n + 1, vector<int>(goal + 1, -1));
        return backTrack(n, goal, k);
    }

private:
    int MOD = 1e9 + 7;
    vector<vector<int>> record;
    long long backTrack(int n, int goal, int k)
    {
        if (n == 0 && goal == 0)
            return 1;
        if (n == 0 || goal == 0)
            return 0;
        if (record[n][goal] != -1)
            return record[n][goal];
        long long pick = backTrack(n - 1, goal - 1, k) * n;
        long long notpick = backTrack(n, goal - 1, k) * max(n - k, 0);
        return record[n][goal] = (pick + notpick) % MOD;
    }
};