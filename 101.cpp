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
    bool isSymmetric(TreeNode *root)
    {
        stack<TreeNode *> left;
        stack<TreeNode *> right;
        left.push(root->left);
        right.push(root->right);
        TreeNode *nowL;
        TreeNode *nowR;

        while (left.size() && right.size())
        {
            nowL = left.top();
            nowR = right.top();
            left.pop();
            right.pop();
            if ((!nowL && nowR) || (nowL && !nowR))
                return false;
            else if (!nowL && !nowR)
                continue;

            if (nowL->val != nowR->val)
                return false;
            left.push(nowL->left);
            left.push(nowL->right);
            right.push(nowR->right);
            right.push(nowR->left);
        }
        return left.size() == right.size();
    }
};