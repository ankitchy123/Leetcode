class Solution
{
public:
    vector<int> solve(int i, vector<vector<int>> &vec, string &labels, vector<int> &ans)
    {
        vector<int> nodeCounts(26, 0);
        ans[i] = 1;
        nodeCounts[labels[i] - 'a'] = 1;

        for (auto &child : vec[i])
        {
            if (!ans[child])
            {
                vector<int> childCounts = solve(child, vec, labels, ans);
                for (int k = 0; k != 26; k++)
                {
                    nodeCounts[k] += childCounts[k];
                }
            }
        }
        ans[i] = nodeCounts[labels[i] - 'a'];
        return nodeCounts;
    }

    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
    {
        vector<vector<int>> vec(n);
        vector<int> ans(n, 0);
        for (int i = 0; i != edges.size(); i++)
        {
            vec[edges[i][0]].push_back(edges[i][1]);
            vec[edges[i][1]].push_back(edges[i][0]);
        }
        solve(0, vec, labels, ans);
        return ans;
    }
};