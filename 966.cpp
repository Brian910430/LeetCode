#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
    {
        unordered_set<string> exact = unordered_set<string>();
        unordered_map<string, string> caseMap = unordered_map<string, string>();
        unordered_map<string, string> vowelMap = unordered_map<string, string>();
        vector<string> ans = vector<string>();
        string temp = "";

        for (int i = 0; i < wordlist.size(); i++)
        {
            exact.insert(wordlist[i]);
            temp = wordlist[i];
            for (auto &c : temp)
                c = tolower(c);
            if (caseMap.find(temp) == caseMap.end())
                caseMap[temp] = wordlist[i];
            for (auto &c : temp)
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                    c = '-';
            if (vowelMap.find(temp) == vowelMap.end())
                vowelMap[temp] = wordlist[i];
        }
        
        for (int i = 0; i < queries.size(); i++)
        {
            if (exact.count(queries[i]))
            {
                ans.push_back(queries[i]);
                continue;
            }

            temp = queries[i];
            for (auto &c : temp)
                c = tolower(c);
            if (caseMap.find(temp) != caseMap.end())
            {
                ans.push_back(caseMap[temp]);
                continue;
            }

            for (auto &c : temp)
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                    c = '-';
            if (vowelMap.find(temp) != vowelMap.end())
            {
                ans.push_back(vowelMap[temp]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};