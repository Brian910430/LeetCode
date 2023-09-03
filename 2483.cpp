#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int n = customers.length();
        int ans = 0;
        int min = INT_MAX;
        vector<int> record(n + 5, 0);
        for (int i = 0; i < n; i++)
            record[i + 1] = record[i] + (customers[i] == 'Y');
        for (int i = 0; i <= n; i++)
        {
            int temp = record[n] - record[i] + i - record[i];
            if (min > temp)
            {
                min = temp;
                ans = i;
            }
        }
        return ans;
    }
};