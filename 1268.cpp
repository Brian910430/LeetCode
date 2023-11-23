#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        trieNode *root = new trieNode();
        vector<vector<string>> ans;
        for (int i = 0; i < products.size(); i++)
        {
            trieNode *now = root;
            for (int j = 0; j < products[i].length(); j++)
            {
                if (now->Link[products[i][j] - 'a'] == nullptr)
                    now->Link[products[i][j] - 'a'] = new trieNode();
                now = now->Link[products[i][j] - 'a'];
                if (j == products[i].length() - 1)
                    now->isEnd = true;
            }
        }
        for (int i = 0; i < searchWord.length(); i++)
            ans.push_back(traversal(root, searchWord.substr(0, i + 1)));
        return ans;
    }

private:
    struct trieNode
    {
        vector<trieNode *> Link;
        bool isEnd;
        trieNode()
        {
            Link.resize(26, nullptr);
            isEnd = false;
        }
    };

    vector<string> traversal(trieNode *root, string prefix)
    {
        vector<string> ans;
        string s = prefix;
        trieNode *now = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (now->Link[prefix[i] - 'a'] == nullptr)
                return ans;
            else
                now = now->Link[prefix[i] - 'a'];
        }
        dfs(now, s, ans);
        return ans;
    }

    void dfs(trieNode *root, string &s, vector<string> &ans)
    {
        if (ans.size() == 3)
            return;
        if (root->isEnd)
            ans.push_back(s);
        for (int i = 0; i < 26; i++)
        {
            if (root->Link[i] != nullptr)
            {
                s.push_back('a' + i);
                dfs(root->Link[i], s, ans);
                s.pop_back();
            }
        }
    }
};