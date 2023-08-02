#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        picked.resize(nums.size(), 0);
        backTrack(nums);
        return ans;
    }

private:
    vector<vector<int>> ans;
    vector<int> temp;
    vector<int> picked;
    void backTrack(vector<int> &nums)
    {
        if (temp.size() == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (picked[i] == 1)
                continue;
            temp.push_back(nums[i]);
            picked[i] = 1;
            backTrack(nums);
            picked[i] = 0;
            temp.pop_back();
        }
    }
};

int main()
{
    Solution solution;
    return 0;
}