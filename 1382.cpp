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
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> record;
        inorder(record, root);
        return buildTree(record, 0, record.size() - 1);
    }

private:
    void inorder(vector<int> &record, TreeNode *root)
    {
        if (root == nullptr)
            return;
        inorder(record, root->left);
        record.push_back(root->val);
        inorder(record, root->right);
    }

    TreeNode *buildTree(vector<int> &record, int left, int right)
    {
        cout << left << " " << right << endl;
        int middle = (left + right) / 2;
        TreeNode *root = new TreeNode(record[middle]);
        if (left != middle)
            root->left = buildTree(record, left, middle - 1);
        if (right != middle)
            root->right = buildTree(record, middle + 1, right);
        return root;
    }
};