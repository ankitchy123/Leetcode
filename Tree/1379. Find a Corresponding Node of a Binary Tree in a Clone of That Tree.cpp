/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    void getNode(TreeNode *original, TreeNode *cloned, TreeNode *target, TreeNode *&node)
    {
        if (original == NULL)
        {
            return;
        }
        if (original == target)
        {
            node = cloned;
            return;
        }

        getNode(original->left, cloned->left, target, node);
        getNode(original->right, cloned->right, target, node);
    }
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        TreeNode *node = NULL;
        getNode(original, cloned, target, node);
        return node;
    }
};