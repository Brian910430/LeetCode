#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<unordered_set<int>> rows = vector<unordered_set<int>>(9, unordered_set<int>());
        vector<unordered_set<int>> cols = vector<unordered_set<int>>(9, unordered_set<int>());
        vector<vector<unordered_set<int>>> grids = vector<vector<unordered_set<int>>>(3, vector<unordered_set<int>>(3, unordered_set<int>()));
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.')
                {
                    int now = board[i][j] - '0';
                    if (rows[i].count(now) || cols[j].count(now) || grids[i / 3][j / 3].count(now))
                        return false;
                    rows[i].insert(now);
                    cols[j].insert(now);
                    grids[i / 3][j / 3].insert(now);
                }
        return true;
    }
};