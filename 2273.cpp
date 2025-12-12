#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> removeAnagrams(vector<string> &words)
    {
        vector<string> ans = vector<string>();
        solve(words, ans, words.size() - 1);
        return ans;
    }

private:
    bool isAnagram(string a, string b)
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a == b;
    }

    int solve(vector<string> &words, vector<string> &ans, int index)
    {
        if (index == 0)
        {
            ans.push_back(words[index]);
            return index;
        }
        int least = solve(words, ans, index - 1);
        if (!isAnagram(words[index], words[least]))
        {
            ans.push_back(words[index]);
            return index;
        }
        return least;
    }
};