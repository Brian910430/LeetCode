#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> ans;
        for (int i = 0; i < asteroids.size(); i++)
        {
            bool crashed = false;
            while (ans.size() && ans.back() > 0 && asteroids[i] < 0)
            {
                if (ans.back() < abs(asteroids[i]))
                {
                    ans.pop_back();
                    continue;
                }
                else if (ans.back() == abs(asteroids[i]))
                    ans.pop_back();
                crashed = true;
                break;
            }
            if (!crashed)
                ans.push_back(asteroids[i]);
        }
        return ans;
    }
};