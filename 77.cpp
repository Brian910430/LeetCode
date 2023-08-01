#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        backTrack(n, k, 1);
        return result;
    }

private:
    vector<vector<int>> result;
    vector<int> temp;
    void backTrack(int n, int k, int start)
    {
        if (k == 0)
        {
            result.push_back(temp);
            return;
        }
        for (int i = start; i <= n; i++)
        {
            temp.push_back(i);
            backTrack(n, k - 1, i + 1);
            temp.pop_back();
        }
    }
};