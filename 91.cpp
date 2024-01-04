#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        if (s.length() == 0 || s[0] == '0')
            return 0;
        int n = s.length();
        vector<int> record(n + 5, 0);
        record[0] = record[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            int a = stoi(s.substr(i - 1, 1));
            int b = stoi(s.substr(i - 2, 2));
            if (a > 0)
                record[i] += record[i - 1];
            if (10 <= b && b <= 26)
                record[i] += record[i - 2];
        }
        return record[n];
    }
};