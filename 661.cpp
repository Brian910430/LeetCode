#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int row = img.size();
        int col = img[0].size();
        vector<vector<int>> ans(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                int sum = 0;
                int cnt = 0;
                for (int x = -1; x <= 1; x++)
                    for (int y = -1; y <= 1; y++)
                    {
                        int nx = i + x;
                        int ny = j + y;
                        if (nx >= 0 && nx < row && ny >= 0 && ny < col)
                        {
                            sum += img[nx][ny];
                            cnt++;
                        }
                    }
                ans[i][j] = sum / cnt;
            }
        return ans;
    }
};