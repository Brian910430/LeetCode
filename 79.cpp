#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        vector<vector<int>> visited = vector<vector<int>>(board.size(), vector<int>(board[0].size(), 0));
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
            {
                visited.assign(board.size(), vector<int>(board[0].size(), 0));
                if (backTrack(board, visited, word, i, j, 0))
                    return true;
            }
        return false;
    }

private:
    bool backTrack(vector<vector<char>> &board, vector<vector<int>> &visited, string word, int x, int y, int index)
    {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || visited[x][y] || board[x][y] != word[index])
            return false;
        visited[x][y] = 1;
        if (index == word.size() - 1)
            return true;
        bool left = backTrack(board, visited, word, x - 1, y, index + 1);
        bool right = backTrack(board, visited, word, x + 1, y, index + 1);
        bool up = backTrack(board, visited, word, x, y - 1, index + 1);
        bool down = backTrack(board, visited, word, x, y + 1, index + 1);
        visited[x][y] = 0;
        return left || right || up || down;
    }
};