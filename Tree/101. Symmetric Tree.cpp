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
    bool isSame(TreeNode *p, TreeNode *q)
    {
        if (p == NULL || q == NULL)
        {
            return p == q;
        }
        if (p->val != q->val || !isSame(p->left, q->right) || !isSame(p->right, q->left))
        {
            return false;
        }

        return true;
    }
    bool isSymmetric(TreeNode *root)
    {
        bool ans = isSame(root->left, root->right);
        return ans;
    }
};