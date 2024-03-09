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
    int diameterOfBinaryTree(TreeNode *root)
    {
        ans = INT_MIN;
        DFS(root);
        return ans - 1;
    }

private:
    int ans;
    int DFS(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = DFS(root->left);
        int right = DFS(root->right);
        ans = max(ans, left + right + 1);
        return max(left, right) + 1;
    }
};