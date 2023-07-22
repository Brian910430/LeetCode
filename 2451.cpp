#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string oddString(vector<string> &words)
    {
        int n = words.size();
        int l = words[0].length();
        vector<string> vec(n, "");
        for (int i = 0; i < n; i++)
            for (int j = 0; j < l - 1; j++)
                vec[i] += ('0' + words[i][j + 1] - words[i][j]);

        if (vec[0] != vec[1])
        {
            if (vec[0] == vec[2])
                return words[1];
            else
                return words[0];
        }
        for (int i = 2; i < n; i++)
            if (vec[i] != vec[0])
                return words[i];
        return "";
    }
};