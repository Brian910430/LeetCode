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
    string tree2str(TreeNode *root)
    {
        ans = "";
        preorder(root);
        ans = ans.substr(1, ans.size() - 2);
        return ans;
    }

private:
    string ans;
    void preorder(TreeNode *now)
    {
        if (now == nullptr)
            return;
        ans += "(";
        ans += to_string(now->val);
        if (now->right != nullptr && now->left == nullptr)
            ans += "()";
        preorder(now->left);
        preorder(now->right);
        ans += ")";
    }
};