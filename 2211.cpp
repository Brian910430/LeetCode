#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countCollisions(string directions)
    {
        int index = 0;
        int sCount = 0;

        for (; index < directions.size() && directions[index] == 'L'; index++)
            ;
        while (directions.size() > 0 && directions.back() == 'R')
            directions.pop_back();
        for (int i = index; i < directions.size(); i++)
            if (directions[i] == 'S')
                sCount++;
        return directions.size() - sCount - index;
    }
};