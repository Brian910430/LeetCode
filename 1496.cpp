#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPathCrossing(string path)
    {
        set<pair<int, int>> visited;
        visited.insert({0, 0});
        int x = 0;
        int y = 0;

        for (int c = 0; c < path.length(); c++)
        {
            if (path[c] == 'E')
                x++;
            else if (path[c] == 'S')
                y--;
            else if (path[c] == 'W')
                x--;
            else
                y++;
            if (visited.count({x, y}))
                return true;
            visited.insert({x, y});
        }
        return false;
    }
};