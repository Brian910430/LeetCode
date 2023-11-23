#include <bits/stdc++.h>
using namespace std;

class Trie
{
public:
    Trie()
    {
        root = new trieNode();
    }

    void insert(string word)
    {
        trieNode *now = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (now->Link[word[i] - 'a'] == nullptr)
                now->Link[word[i] - 'a'] = new trieNode();
            now = now->Link[word[i] - 'a'];
            if (i == word.length() - 1)
                now->isEnd = true;
        }
    }

    bool search(string word)
    {
        trieNode *now = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (now->Link[word[i] - 'a'] == nullptr)
                return false;
            now = now->Link[word[i] - 'a'];
        }
        return now->isEnd;
    }

    bool startsWith(string prefix)
    {
        trieNode *now = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (now->Link[prefix[i] - 'a'] == nullptr)
                return false;
            now = now->Link[prefix[i] - 'a'];
        }
        return true;
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
    trieNode *root;
};