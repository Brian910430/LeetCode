#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        int x = coordinates[0][0];
        int y = coordinates[0][1];
        for (int i = 1; i < coordinates.size(); i++)
        {
            if (coordinates[i][1] != y)
                break;
            if (i == coordinates.size() - 1)
                return true;
        }
        double slope = (double)(coordinates[1][0] - x) / (coordinates[1][1] - y);

        for (int i = 1; i < coordinates.size(); i++)
        {
            double temp = (double)(coordinates[i][0] - x) / (coordinates[i][1] - y);
            if (slope != temp)
                return false;
        }
        return true;
    }
};