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
    int longestZigZag(TreeNode *root)
    {
        ans = 0;
        findZigZag(root, 0, 0);
        return ans;
    }

private:
    int ans;
    void findZigZag(TreeNode *root, int direction, int length)
    {
        if (root == nullptr)
            return;
        ans = max(ans, length);
        if (length == 0)
        {
            findZigZag(root->left, 0, 1);
            findZigZag(root->right, 1, 1);
        }
        else if (direction == 0)
        {
            findZigZag(root->left, 0, 1);
            findZigZag(root->right, 1, length + 1);
        }
        else
        {
            findZigZag(root->left, 0, length + 1);
            findZigZag(root->right, 1, 1);
        }
    }
};