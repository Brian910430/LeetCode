#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getLengthOfOptimalCompression(string s, int k)
    {
        int n = s.size();
        record = vector<vector<int>>(n + 5, vector<int>(k + 5, -1));
        ans = INT_MAX;
    }

private:
    vector<vector<int>> record;
    int ans;
    void backTrack(string s, int k, int index, string cur)
    {
        if (cur.size() == s.size() - k)
        {
            ;
        }
    }
};

int main()
{
    Solution solution;
    string s = "aaaaaaa";
    return 0;
}