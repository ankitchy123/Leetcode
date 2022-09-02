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
    vector<double> averageOfLevels(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<double> vec;

        double sum = 0;
        int num = 0;

        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp)
            {
                sum += temp->val;
                num++;
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
                q.push(NULL);
                vec.push_back(sum / num);
                sum = num = 0;
            }
        }
        vec.push_back(sum / num);
        return vec;
    }
};