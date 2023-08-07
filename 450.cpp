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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return nullptr;
        TreeNode *now = root;
        TreeNode *prev = root;
        while (now != nullptr)
        {
            if (now->val < key)
            {
                prev = now;
                now = now->right;
            }
            else if (now->val > key)
            {
                prev = now;
                now = now->left;
            }
            else
                break;
        }

        if (now == nullptr)
            return root;
        else if (now->left == nullptr && now->right == nullptr)
        {
            if (now == root)
                return nullptr;
            if (prev->left == now)
                prev->left = nullptr;
            else
                prev->right = nullptr;
            return root;
        }
        else if (now->right != nullptr)
        {
            ;
        }
        else
        {
            ;
        }
    }
};

int main()
{
    Solution solution;
    return 0;
}