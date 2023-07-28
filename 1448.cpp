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
    int goodNodes(TreeNode *root)
    {
        ans = 0;
        DFS(root, root->val);
        return ans;
    }

private:
    int ans;
    void DFS(TreeNode *root, int maxVal)
    {
        if (root == nullptr)
            return;
        if (root->val >= maxVal)
            ans++;
        maxVal = max(root->val, maxVal);
        DFS(root->left, maxVal);
        DFS(root->right, maxVal);
    }
};