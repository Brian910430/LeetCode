#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDistance(vector<int> &position, int m)
    {
        sort(position.begin(), position.end());
        int left = 0;
        int right = position[position.size() - 1] - position[0];
        int middle = 0;

        while (left < right)
        {
            middle = (left + right + 1) / 2;
            if (check(position, m, middle))
                left = middle;
            else
                right = middle - 1;
        }
        return left;
    }

private:
    bool check(vector<int> &position, int m, int middle)
    {
        int now = position[0];
        for (int i = 0; i < position.size(); i++)
            if (position[i] - now >= middle)
            {
                m--;
                now = position[i];
            }
        return m <= 1;
    }
};