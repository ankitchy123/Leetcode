/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
        {
            return "";
        }
        return to_string(root->val) + "-" + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        string s;
        vector<int> vec;
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] != '-')
            {
                s.push_back(data[i]);
            }
            else
            {
                vec.push_back(stoi(s));
                s.clear();
            }
        }

        TreeNode *root = NULL;
        for (int i = 0; i < vec.size(); i++)
        {
            root = InsertInBST(root, vec[i]);
        }

        return root;
    }
    TreeNode *InsertInBST(TreeNode *root, int num)
    {
        // base case
        if (!root)
        {
            root = new TreeNode(num);
            return root;
        }

        // recursive case
        if (num < root->val)
        {
            root->left = InsertInBST(root->left, num);
        }
        else
        {
            root->right = InsertInBST(root->right, num);
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;