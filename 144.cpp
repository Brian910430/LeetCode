#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return ans;

        ans.push_back(root->val);
        if (root->left != NULL)
            preorderTraversal(root->left);
        if (root->right != NULL)
            preorderTraversal(root->right);
        return ans;
    }
};