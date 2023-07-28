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
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        stack<int> leafs1;
        stack<int> leafs2;
        DFS(root1, leafs1);
        DFS(root2, leafs2);
        if (leafs1.size() != leafs2.size())
            return false;
        while (leafs1.size())
        {
            if (leafs1.top() != leafs2.top())
                return false;
            leafs1.pop();
            leafs2.pop();
        }
        return true;
    }

private:
    void DFS(TreeNode *root, stack<int> &leafs)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
            leafs.push(root->val);
        DFS(root->left, leafs);
        DFS(root->right, leafs);
    }
};