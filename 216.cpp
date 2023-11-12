#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        backTrack(k, n);
        return ans;
    }

private:
    vector<vector<int>> ans;
    vector<int> temp;
    void backTrack(int remain, int goal)
    {
        if (goal < 0)
            return;
        if (remain == 0)
        {
            if (goal == 0)
                ans.push_back(temp);
            return;
        }
        int now = temp.empty() ? 1 : temp[temp.size() - 1] + 1;
        for (; now <= 9; now++)
        {
            temp.push_back(now);
            backTrack(remain - 1, goal - now);
            temp.pop_back();
        }
    }
};