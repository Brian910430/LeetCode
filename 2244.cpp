#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        map<int, int> map;
        int count = 0;
        int n = tasks.size();
        for (int i = 0; i < n; i++)
            if (map.find(tasks[i]) == map.end())
                map[tasks[i]] = 1;
            else
                map[tasks[i]]++;

        for (auto a : map)
        {
            if (a.second == 1)
                return -1;
            else
            {
                int quotient = a.second / 3;
                int remainder = a.second % 3;
                if (remainder == 0)
                    count += quotient;
                else
                    count += quotient + 1;
            }
        }
        return count;
    }
};
