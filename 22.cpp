#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        s = "";
        ans = vector<string>();
        backTrack(n, n);
        return ans;
    }

private:
    string s;
    vector<string> ans;
    void backTrack(int left, int right)
    {
        if (left == 0 && right == 0)
        {
            ans.push_back(s);
            return;
        }
        if (right == 0)
            return;
        if (left > 0)
        {
            s += '(';
            backTrack(left - 1, right);
            s.pop_back();
        }
        if (right > left)
        {
            s += ')';
            backTrack(left, right - 1);
            s.pop_back();
        }
    }
};