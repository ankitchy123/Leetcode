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
    pair<int, int> solve(TreeNode *root, int &ans)
    {
        if (!root)
        {
            return {0, 0};
        }
        int size = 1;
        pair<int, int> left = solve(root->left, ans);
        pair<int, int> right = solve(root->right, ans);

        if (left.second > 0)
        {
            size += left.second;
        }
        if (right.second > 0)
        {
            size += right.second;
        }
        int sum = root->val + left.first + right.first;
        if (root->val == sum / size)
        {
            ans++;
        }
        return {sum, size};
    }

    int averageOfSubtree(TreeNode *root)
    {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};