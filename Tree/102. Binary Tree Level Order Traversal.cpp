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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        levelOrder(root, ans);
        return ans;
    }

    void levelOrder(TreeNode *root, vector<vector<int>> &ans)
    {
        if (root == NULL)
        {
            return;
        }

        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<int> vec;

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node != NULL)
            {
                vec.push_back(node->val);
                if (node->left != NULL)
                {
                    q.push(node->left);
                }
                if (node->right != NULL)
                {
                    q.push(node->right);
                }
            }
            else if (!q.empty())
            {
                q.push(NULL);
            }
            if (node == NULL)
            {
                ans.push_back(vec);
                vec.clear();
            }
        }
    }
};