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
    int getMinimumDifference(TreeNode *root)
    {
        inorder(root);
        for (int i = 0; i < record.size() - 1; i++)
            ans = min(ans, record[i + 1] - record[i]);
        return ans;
    }

private:
    int ans = INT_MAX;
    vector<int> record;

    void inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        inorder(root->left);
        record.push_back(root->val);
        inorder(root->right);
    }
};