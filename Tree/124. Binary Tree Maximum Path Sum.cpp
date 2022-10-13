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
    int ans = INT_MIN;
    int solve(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int data = root->val;
        int l = solve(root->left);
        int r = solve(root->right);

        int maxSum = max({data, l + data, r + data});

        ans = max({ans, maxSum, data + l + r});
        return maxSum;
    }
    int maxPathSum(TreeNode *root)
    {
        solve(root);
        return ans;
    }
};