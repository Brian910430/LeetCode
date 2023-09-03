#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s3.length() != s1.length() + s2.length())
            return false;
        record.resize(s1.length() + 5, vector<int>(s2.length() + 5, -1));
        return solve(s1, s2, s3, 0, 0, 0);
    }

private:
    bool solve(string &s1, string &s2, string &s3, int i1, int i2, int i3)
    {
        if (record[i1][i2] != -1)
            return record[i1][i2];
        bool check = false;
        if (i3 == s3.length())
            check = true;
        else if (s1[i1] == s3[i3] && s2[i2] == s3[i3])
            check = solve(s1, s2, s3, i1 + 1, i2, i3 + 1) || solve(s1, s2, s3, i1, i2 + 1, i3 + 1);
        else if (s1[i1] == s3[i3])
            check = solve(s1, s2, s3, i1 + 1, i2, i3 + 1);
        else if (s2[i2] == s3[i3])
            check = solve(s1, s2, s3, i1, i2 + 1, i3 + 1);
        return record[i1][i2] = check;
    }
    vector<vector<int>> record;
};