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
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        vector<vector<TreeNode *>> vec;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<TreeNode *> vec2;

        // 2
        // 3 5 NULL 8 13
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp)
            {
                vec2.push_back(temp);
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            else if (!q.empty())
            {
                vec.push_back(vec2);
                vec2 = {};
                q.push(NULL);
            }
        }
        vec.push_back(vec2);

        for (int i = 0; i < vec.size(); i++)
        {
            if (i % 2 != 0)
            {
                int s = 0, e = vec[i].size() - 1;
                while (s < e)
                {
                    swap(vec[i][s]->val, vec[i][e]->val);
                    s++;
                    e--;
                }
            }
        }
        return root;
    }
};