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
    long long ans = 0;
    void Sum(TreeNode *root, long long &total)
    {
        if (!root)
        {
            return;
        }
        total += root->val;
        Sum(root->left, total);
        Sum(root->right, total);
    }
    int subtreeSum(TreeNode *root, long long total)
    {
        if (!root)
        {
            return 0;
        }
        int left = subtreeSum(root->left, total);
        int right = subtreeSum(root->right, total);
        ans = max(ans, max((total - left) * left, (total - right) * right));
        return left + right + root->val;
    }
    int maxProduct(TreeNode *root)
    {
        long long total = 0;
        Sum(root, total);
        subtreeSum(root, total);
        int MOD = 1e9 + 7;
        return ans % MOD;
    }
};