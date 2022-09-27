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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        deque<TreeNode *> q;
        for (int i = 0; i < nums.size(); i++)
        {
            TreeNode *temp = new TreeNode(nums[i]);

            while (!q.empty() && q.back()->val < nums[i])
            {
                temp->left = q.back();
                q.pop_back();
            }

            if (!q.empty())
            {
                q.back()->right = temp;
            }

            q.emplace_back(temp);
        }
        return q.front();
    }
};