#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPath(vector<int> &parent, string s)
    {
        ;
    }
};

int main()
{
    Solution solution;
    vector<int> parent = {-1, 0, 0, 1, 1, 2};
    string s = "abacbe";
    cout << solution.longestPath(parent, s) << endl;
    parent = {-1, 0, 0, 0};
    s = "aabc";
    cout << solution.longestPath(parent, s) << endl;
    return 0;
}