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
    void preorder(TreeNode *root, string &s)
    {
        s += to_string(root->val);

        s += "(";
        if (root->left)
        {
            preorder(root->left, s);
        }
        s += ")";

        if (root->right)
        {
            s += "(";
            preorder(root->right, s);
            s += ")";
        }

        else if (!root->left)
        {
            s.erase(s.end() - 2, s.end());
        }
    }

    string tree2str(TreeNode *root)
    {
        string str = "";
        preorder(root, str);

        return str;
    }
};