#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        unordered_set<char> record = unordered_set<char>();
        vector<string> s = split(text);
        int ans = 0;

        for (int i = 0; i < brokenLetters.length(); i++)
            record.insert(brokenLetters[i]);
        for (int i = 0; i < s.size(); i++)
        {
            for (auto c : s[i])
                if (record.count(c))
                {
                    ans--;
                    break;
                }
            ans++;
        }
        return ans;
    }

private:
    vector<string> split(string &text)
    {
        vector<string> s = vector<string>();
        for (int i = 0; i < text.length(); i++)
        {
            string temp = "";
            while (i < text.length() && text[i] != ' ')
                temp += text[i++];
            s.push_back(temp);
        }
        return s;
    }
};