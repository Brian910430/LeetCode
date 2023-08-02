#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        DFS(root, p, q);
        return ans;
    }

private:
    TreeNode *ans;
    TreeNode *DFS(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;
        TreeNode *left = DFS(root->left, p, q);
        TreeNode *right = DFS(root->right, p, q);

        if (left != nullptr && right != nullptr)
        {
            ans = root;
            return nullptr;
        }
        else if (left != nullptr || right != nullptr)
        {
            if (root == p || root == q)
                ans = root;
            return root;
        }
        if (root == p)
            return root;
        if (root == q)
            return root;
        return nullptr;
    }
};