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
    int ans = 0;
    int sumOfLeftLeaves(TreeNode *root)
    {
        ans = 0;
        DFS(root, false);
        return ans;
    }

private:
    void DFS(TreeNode *root, bool left)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr && left)
            ans += root->val;
        DFS(root->left, true);
        DFS(root->right, false);
    }
};