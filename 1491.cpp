#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double average(vector<int> &salary)
    {
        int sum = 0;
        int max = INT_MIN;
        int min = INT_MAX;
        for (int i = 0; i < salary.size(); i++)
        {
            sum += salary[i];
            if (max < salary[i])
                max = salary[i];
            if (salary[i] < min)
                min = salary[i];
        }
        return (double)(sum - min - max) / (salary.size() - 2);
    }
};