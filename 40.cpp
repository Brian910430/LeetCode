#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        ans = vector<vector<int>>();
        record = vector<int>();
        sort(candidates.begin(), candidates.end());
        backTrack(candidates, target, 0);
        return ans;
    }

private:
    vector<vector<int>> ans;
    vector<int> record;
    void backTrack(vector<int> &candidates, int target, int index)
    {
        if (target == 0)
        {
            ans.push_back(record);
            return;
        }
        if (target < 0 || index == candidates.size())
            return;
        for (int i = index; i < candidates.size(); i++)
        {
            record.push_back(candidates[i]);
            backTrack(candidates, target - candidates[i], i + 1);
            record.pop_back();
            while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
                i++;
        }
    }
};