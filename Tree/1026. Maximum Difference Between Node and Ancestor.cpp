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
    void solve(TreeNode *root, int currMax, int currMin)
    {
        if (!root)
        {
            return;
        }

        int temp = max(abs(currMax - root->val), abs(currMin - root->val));
        ans = max(ans, temp);
        currMax = max(currMax, root->val);
        currMin = min(currMin, root->val);
        solve(root->left, currMax, currMin);
        solve(root->right, currMax, currMin);
        return;
    }
    int maxAncestorDiff(TreeNode *root)
    {
        if (!root)
        {
            return ans;
        }
        solve(root, root->val, root->val);
        return ans;
    }
};