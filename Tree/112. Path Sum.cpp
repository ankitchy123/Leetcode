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
    bool flag = false;
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root != NULL)
        {
            targetSum -= root->val;

            if (targetSum == 0 && root->left == NULL && root->right == NULL)
            {
                flag = true;
                return true;
            }

            hasPathSum(root->left, targetSum);

            hasPathSum(root->right, targetSum);
        }

        return flag;
    }
};