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
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        TreeNode *head = new TreeNode(INT_MIN, root, nullptr);
        DFS(head, target);
        return head->left;
    }

private:
    bool DFS(TreeNode *root, int target)
    {
        if (root == nullptr)
            return true;
        bool left = DFS(root->left, target);
        bool right = DFS(root->right, target);
        root->left = left ? nullptr : root->left;
        root->right = right ? nullptr : root->right;
        return left && right && root->val == target;
    }
};