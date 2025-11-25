#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        sort(folder.begin(), folder.end());
        vector<string> ans = vector<string>();
        string last = "leetcode";
        for (int i = 0; i < folder.size(); i++)
        {
            if (folder[i].find(last + "/") != 0)
            {
                last = folder[i];
                ans.push_back(last);
            }
        }
        return ans;
    }
};