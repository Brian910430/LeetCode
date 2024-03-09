#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        ans = vector<vector<int>>();
        record = vector<int>();
        backTrack(candidates, target, 0);
        return ans;
    }

private:
    vector<int> record;
    vector<vector<int>> ans;
    void backTrack(vector<int> &candidates, int target, int index)
    {
        int n = candidates.size();
        if (target == 0)
        {
            ans.push_back(record);
            return;
        }
        if (target < 0)
            return;
        for (int i = index; i < n; i++)
        {
            record.push_back(candidates[i]);
            backTrack(candidates, target - candidates[i], i);
            record.pop_back();
        }
    }
};