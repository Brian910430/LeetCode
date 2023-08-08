#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        queue<pair<int, int>> nextStep;
        vector<vector<int>> record(maze.size(), vector<int>(maze[0].size(), 0));
        vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        nextStep.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        while (nextStep.size())
        {
            int nowX = nextStep.front().first;
            int nowY = nextStep.front().second;
            nextStep.pop();
            for (int i = 0; i < 4; i++)
            {
                int x = nowX + direction[i][0];
                int y = nowY + direction[i][1];
                if (0 <= x && x < maze.size() && 0 <= y && y < maze[0].size() && maze[x][y] == '.')
                {
                    maze[x][y] = '+';
                    record[x][y] = record[nowX][nowY] + 1;
                    if (x == 0 || x == maze.size() - 1 || y == 0 || y == maze[0].size() - 1)
                        return record[x][y];
                    nextStep.push({x, y});
                }
            }
        }
        return -1;
    }
};