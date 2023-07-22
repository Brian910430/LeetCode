#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPoints(string rings)
    {
        int n = rings.length();
        int ans = 0;
        int rod;
        char color;
        vector<vector<int>> vec = vector<vector<int>>(10, vector<int>(3, 0));
        for (int i = 0; i < n; i += 2)
        {
            color = rings[i];
            rod = rings[i + 1] - '0';
            if (color == 'R')
                vec[rod][0]++;
            else if (color == 'G')
                vec[rod][1]++;
            else if (color == 'B')
                vec[rod][2]++;
        }
        for (int i = 0; i < 10; i++)
            if (vec[i][0] && vec[i][1] && vec[i][2])
                ans++;
        return ans;
    }
};