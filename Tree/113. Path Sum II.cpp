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
    vector<vector<int>> ans;
    vector<int> vec;

    void solve(TreeNode *root, int sum, int targetSum)
    {
        if (!root)
        {
            return;
        }

        vec.push_back(root->val);
        sum += root->val;
        if (sum == targetSum && !root->left && !root->right)
        {
            ans.push_back(vec);
        }

        solve(root->left, sum, targetSum);
        solve(root->right, sum, targetSum);
        vec.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        int sum = 0;
        solve(root, sum, targetSum);
        return ans;
    }
};