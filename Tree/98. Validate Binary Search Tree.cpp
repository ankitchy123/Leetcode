/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool solve(TreeNode *root, TreeNode *low, TreeNode *high)
    {
        if (!root)
        {
            return true;
        }

        if (low && (root->val <= low->val))
        {
            return false;
        }
        if (high && (root->val >= high->val))
        {
            return false;
        }

        bool l = solve(root->left, low, root);
        bool r = solve(root->right, root, high);
        return l && r;
    }
    bool isValidBST(TreeNode *root)
    {
        return solve(root, NULL, NULL);
    }
};