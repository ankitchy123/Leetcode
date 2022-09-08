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
    void solve(TreeNode *root, int k, int &n)
    {
        if (!root)
        {
            return;
        }

        solve(root->left, k, n);
        n++;
        if (k == n)
        {
            ans = root->val;
            return;
        }
        solve(root->right, k, n);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        int n = 0;
        solve(root, k, n);
        return ans;
    }
};