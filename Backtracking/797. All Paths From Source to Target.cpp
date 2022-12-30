class Solution
{
public:
    void solve(vector<vector<int>> &graph, int ind, vector<vector<int>> &ans, vector<int> &vec)
    {
        vec.push_back(ind);
        if (ind == graph.size() - 1)
        {
            ans.push_back(vec);
        }
        else
        {
            for (int i = 0; i < graph[ind].size(); i++)
            {
                solve(graph, graph[ind][i], ans, vec);
            }
        }
        vec.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> ans;
        vector<int> vec;
        solve(graph, 0, ans, vec);
        return ans;
    }
};