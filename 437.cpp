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
    int pathSum(TreeNode *root, int targetSum)
    {
        ans = 0;
        DFS(root, targetSum);
        return ans;
    }

private:
    int ans;
    void DFS(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return;
        DFS2(root, targetSum);
        DFS(root->left, targetSum);
        DFS(root->right, targetSum);
    }

    void DFS2(TreeNode *root, long long targetSum)
    {
        if (root == nullptr)
            return;
        if (root->val == targetSum)
            ans++;
        DFS2(root->left, targetSum - root->val);
        DFS2(root->right, targetSum - root->val);
    }
};