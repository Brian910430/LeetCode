#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        vector<int> row = vector<int>(mat.size(), 0);
        vector<int> col = vector<int>(mat[0].size(), 0);
        int ans = 0;

        for (int i = 0; i < mat.size(); i++)
            for (int j = 0; j < mat[0].size(); j++)
            {
                row[i] += mat[i][j];
                col[j] += mat[i][j];
            };
        for (int i = 0; i < mat.size(); i++)
            for (int j = 0; j < mat[0].size(); j++)
                if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1)
                    ans++;
        return ans;
    }
};