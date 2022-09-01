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
    int ans = 0;
    void findNode(TreeNode *root, int num)
    {
        if (root)
        {
            if (root->val >= num)
            {
                num = root->val;
                ans++;
            }
            findNode(root->left, num);
            findNode(root->right, num);
        }
    }
    int goodNodes(TreeNode *root)
    {
        findNode(root, root->val);
        return ans;
    }
};