class Solution
{
public:
    int solve(int i, int p, vector<vector<int>> &vec, vector<bool> &hasApple)
    {
        int ans = 0;
        for (auto node : vec[i])
        {
            if (node != p)
            {
                ans += solve(node, i, vec, hasApple) + 2;
            }
        }
        if (ans == 0)
        {
            if (hasApple[i] && i > 0)
            {
                return 0;
            }
            else
            {
                return -2;
            }
        }
        return ans;
    }
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {
        vector<vector<int>> vec(n);
        for (int i = 0; i < edges.size(); i++)
        {
            vec[edges[i][0]].push_back(edges[i][1]);
            vec[edges[i][1]].push_back(edges[i][0]);
        }
        int time = solve(0, -1, vec, hasApple);
        if (time < 0)
        {
            return 0;
        }
        return time;
    }
};