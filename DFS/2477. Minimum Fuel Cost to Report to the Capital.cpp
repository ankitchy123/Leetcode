class Solution
{
public:
    long long ans = 0;
    long long solve(int node, int p, vector<vector<int>> &vec, int seats)
    {
        int rep = 1;
        for (auto i : vec[node])
        {
            if (i != p)
            {
                rep += solve(i, node, vec, seats);
            }
        }

        if (node != 0)
        {
            ans += ceil((double)rep / seats);
        }
        return rep;
    }
    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        vector<vector<int>> vec(roads.size() + 1);
        for (int i = 0; i < roads.size(); i++)
        {
            vec[roads[i][0]].push_back(roads[i][1]);
            vec[roads[i][1]].push_back(roads[i][0]);
        }
        solve(0, -1, vec, seats);
        return ans;
    }
};