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
    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;
        return DFS(root) == -1 ? false : true;
    }

    int DFS(TreeNode *now)
    {
        if (!now)
            return 0;
        int l = DFS(now->left);
        int r = DFS(now->right);
        if (l == -1 || r == -1 || abs(l - r) > 1)
            return -1;
        else
            return max(l, r) + 1;
    }
};