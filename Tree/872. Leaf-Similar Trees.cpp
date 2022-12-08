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
    int solve(stack<TreeNode *> &s)
    {
        while (1)
        {
            TreeNode *temp = s.top();
            s.pop();
            if (temp->right)
            {
                s.push(temp->right);
            }
            if (temp->left)
            {
                s.push(temp->left);
            }
            if (!temp->left && !temp->right)
            {
                return temp->val;
            }
        }
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        stack<TreeNode *> s1, s2;
        s1.push(root1);
        s2.push(root2);

        while (!s1.empty() && !s2.empty())
        {
            if (solve(s1) != solve(s2))
            {
                return false;
            }
        }
        return s1.empty() && s2.empty();
    }
};