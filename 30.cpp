#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        unordered_multiset<string> wordSet = unordered_multiset<string>(words.begin(), words.end());
        vector<int> ans = vector<int>();
        int l = words[0].length();
        int n = words.size();

        for (int start = 0; start < l; start++)
        {
            unordered_multiset<string> temp = unordered_multiset<string>();
            for (int i = 0; i < n - 1 && (start + i * l) < s.length(); i++)
                temp.insert(s.substr(start + i * l, l));
            for (int index = start + (n - 1) * l; index + l <= s.length(); index += l)
            {
                temp.insert(s.substr(index, l));
                if (temp == wordSet)
                    ans.push_back(index - (n - 1) * l);
                temp.erase(temp.find((s.substr(index - (n - 1) * l, l))));
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};