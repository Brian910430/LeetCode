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
    int minDepth(TreeNode *root)
    {
        return DFS(root) + 1;
    }

    int DFS(TreeNode *now)
    {
        if (!now)
            return -1;
        int l = DFS(now->left);
        int r = DFS(now->right);
        if (l == -1 && r == -1)
            return 0;
        else if (l == -1)
            return r + 1;
        else if (r == -1)
            return l + 1;
        else
            return min(l, r) + 1;
    }
};