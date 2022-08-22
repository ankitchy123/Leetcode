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
class FindElements
{
    void addEle(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            return;
        }

        mp[val] = true;
        addEle(root->left, 2 * val + 1);
        addEle(root->right, 2 * val + 2);
    }

public:
    map<int, bool> mp;
    FindElements(TreeNode *root)
    {
        addEle(root, 0);
    }

    bool find(int target)
    {
        if (mp[target])
        {
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */