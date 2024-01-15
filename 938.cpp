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
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int ans = 0;
        inorder(root);
        for (int i = 0; i < elements.size(); i++)
            if (elements[i] >= low && elements[i] <= high)
                ans += elements[i];
        return ans;
    }

private:
    vector<int> elements;
    void inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        inorder(root->left);
        elements.push_back(root->val);
        inorder(root->right);
    }
};