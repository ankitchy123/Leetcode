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
    int solve(TreeNode *root, unordered_map<int, int> &mp, int &freq)
    {
        if (!root)
        {
            return 0;
        }

        int left = solve(root->left, mp, freq);
        int right = solve(root->right, mp, freq);
        int curr = root->val + left + right;

        mp[curr]++;
        freq = max(freq, mp[curr]);
        return curr;
    }
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        unordered_map<int, int> mp;
        int freq = 0;
        solve(root, mp, freq);

        vector<int> ans;
        for (auto i : mp)
        {
            if (i.second == freq)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};