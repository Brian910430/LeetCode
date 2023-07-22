#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        vector<int> pointed = vector<int>(n, 0);
        vector<int> ans = vector<int>();
        for (auto i : edges)
            pointed[i[1]]++;

        for (int i = 0; i < n; i++)
            if (pointed[i] == 0)
                ans.push_back(i);
        return ans;
    }
};