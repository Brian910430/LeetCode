#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        queue<pair<int, TreeNode *>> record;
        int depth = 0;
        if (root == nullptr)
            return ans;
        record.push({1, root});

        while (record.size())
        {
            pair<int, TreeNode *> now = record.front();
            record.pop();
            if (now.first == depth)
                ans[ans.size() - 1] = now.second->val;
            else
            {
                depth = now.first;
                ans.push_back(now.second->val);
            }
            if (now.second->left != nullptr)
                record.push({now.first + 1, now.second->left});
            if (now.second->right != nullptr)
                record.push({now.first + 1, now.second->right});
        }
        return ans;
    }
};