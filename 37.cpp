#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        vector<unordered_set<int>> rows = vector<unordered_set<int>>(9, {1, 2, 3, 4, 5, 6, 7, 8, 9});
        vector<unordered_set<int>> cols = vector<unordered_set<int>>(9, {1, 2, 3, 4, 5, 6, 7, 8, 9});
        vector<vector<unordered_set<int>>> grids = vector<vector<unordered_set<int>>>(3, vector<unordered_set<int>>(3, {1, 2, 3, 4, 5, 6, 7, 8, 9}));
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.')
                {
                    int now = board[i][j] - '0';
                    rows[i].erase(now);
                    cols[j].erase(now);
                    grids[i / 3][j / 3].erase(now);
                }
        backTrack(board, rows, cols, grids, 0, 0);
    }

private:
    bool backTrack(vector<vector<char>> &board, vector<unordered_set<int>> &rows, vector<unordered_set<int>> &cols, vector<vector<unordered_set<int>>> &grids, int x, int y)
    {
        if (x == 8 && y == 8)
        {
            if (board[x][y] != '.')
                return true;
            for (auto i : rows[x])
            {
                board[x][y] = i + '0';
                return true;
            }
        }
        if (board[x][y] != '.')
        {
            if (y == 8)
                return backTrack(board, rows, cols, grids, x + 1, 0);
            else
                return backTrack(board, rows, cols, grids, x, y + 1);
        }
        auto now = rows[x];
        for (auto i : now)
        {
            if (cols[y].count(i) && grids[x / 3][y / 3].count(i))
            {
                rows[x].erase(i);
                cols[y].erase(i);
                grids[x / 3][y / 3].erase(i);
                board[x][y] = i + '0';
                if (y == 8)
                {
                    if (backTrack(board, rows, cols, grids, x + 1, 0))
                        return true;
                }
                else
                {
                    if (backTrack(board, rows, cols, grids, x, y + 1))
                        return true;
                }
                rows[x].insert(i);
                cols[y].insert(i);
                grids[x / 3][y / 3].insert(i);
                board[x][y] = '.';
            }
        }
        return false;
    }
};