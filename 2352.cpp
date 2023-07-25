#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int ans = 0;
        bool flag = true;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                for (int k = 0, l = 0; k < n; k++, l++)
                    if (grid[i][k] != grid[l][j])
                    {
                        flag = false;
                        break;
                    }
                if (flag)
                    ans++;
                flag = true;
            }
        return ans;
    }
};