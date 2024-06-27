#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        stringstream ss(sentence);
        string ans = "";
        string word;

        while (ss >> word)
        {
            string prefix = "";
            for (int i = 0; i < word.size(); i++)
            {
                prefix += word[i];
                if (dict.count(prefix))
                    break;
            }
            ans += (prefix + " ");
        }
        ans.pop_back();
        return ans;
    }
};