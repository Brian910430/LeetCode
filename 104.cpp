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
    int ans;
    int maxDepth(TreeNode *root)
    {
        ans = 0;
        DFS(root, 1);
        return ans;
    }

    void DFS(TreeNode *now, int depth)
    {
        if (now == nullptr)
            return;
        ans = max(depth, ans);
        DFS(now->left, depth + 1);
        DFS(now->right, depth + 1);
    }
};