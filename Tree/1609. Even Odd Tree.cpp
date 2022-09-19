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
    bool isEvenOddTree(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        queue<TreeNode *> q;
        q.push(root);
        int j = 0;

        while (!q.empty())
        {
            int n = q.size();
            vector<int> vec;
            if (j % 2 == 0)
            {
                TreeNode *temp = q.front();
                q.pop();
                vec.push_back(temp->val);
                if (temp->val % 2 == 0)
                {
                    return false;
                }
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
                int prev = temp->val;
                for (int i = 1; i < n; i++)
                {
                    temp = q.front();
                    q.pop();
                    if (temp->val % 2 == 0 || (temp->val <= prev))
                    {
                        return false;
                    }
                    prev = temp->val;
                    vec.push_back(temp->val);

                    if (temp->left)
                    {
                        q.push(temp->left);
                    }
                    if (temp->right)
                    {
                        q.push(temp->right);
                    }
                }
            }
            else if (j % 2 == 1)
            {
                TreeNode *temp = q.front();
                q.pop();
                vec.push_back(temp->val);
                if (temp->val % 2 == 1)
                {
                    return false;
                }
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }

                int prev = temp->val;
                for (int i = 1; i < n; i++)
                {
                    temp = q.front();
                    q.pop();
                    if (temp->val % 2 == 1 || (temp->val >= prev))
                    {
                        return false;
                    }
                    prev = temp->val;
                    vec.push_back(temp->val);

                    if (temp->left)
                    {
                        q.push(temp->left);
                    }
                    if (temp->right)
                    {
                        q.push(temp->right);
                    }
                }
            }
            j++;
        }

        return true;
    }
};