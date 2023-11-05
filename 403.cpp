#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canCross(vector<int> &stones)
    {
        record.resize(stones.size(), vector<int>(stones.size(), -1));
        return backTrack(stones, 0, 0);
    }

private:
    vector<vector<int>> record;
    bool backTrack(vector<int> &stones, int index, int lastJump)
    {
        int n = stones.size();
        if (index == n - 1)
            return true;
        if (record[index][lastJump] != -1)
            return record[index][lastJump];
        bool flag = false;
        for (int i = index + 1; i < n && stones[i] - stones[index] <= lastJump + 1; i++)
        {
            if (lastJump != 0)
            {
                flag = flag || (stones[i] - stones[index] == lastJump - 1) && backTrack(stones, i, lastJump - 1);
                flag = flag || (stones[i] - stones[index] == lastJump) && backTrack(stones, i, lastJump);
            }
            flag = flag || (stones[i] - stones[index] == lastJump + 1) && backTrack(stones, i, lastJump + 1);
        }
        record[index][lastJump] = flag;
        return flag;
    }
};