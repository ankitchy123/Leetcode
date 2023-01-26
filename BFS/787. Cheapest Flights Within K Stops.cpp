class Solution
{
public:
    void Bellman(vector<vector<int>> flights, vector<int> &ans, int src, int dst, int k)
    {
        ans[src] = 0;
        for (int i = 0; i <= k; i++)
        {
            vector<int> temp(ans);
            for (int i = 0; i < flights.size(); i++)
            {
                if (ans[flights[i][0]] != INT_MAX)
                {
                    temp[flights[i][1]] = min(temp[flights[i][1]], ans[flights[i][0]] + flights[i][2]);
                }
            }
            ans = temp;
        }
    }
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < flights.size(); i++)
        {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        vector<int> ans(n, INT_MAX);
        queue<pair<int, int>> q;
        q.push({src, 0});

        while (k-- >= 0 && !q.empty())
        {
            int temp = q.size();
            while (temp--)
            {
                int curr = q.front().first;
                int dist = q.front().second;
                q.pop();
                for (auto &[nbr, price] : adj[curr])
                {
                    if (price + dist < ans[nbr])
                    {
                        ans[nbr] = price + dist;
                        q.push({nbr, ans[nbr]});
                    }
                }
            }
        }

        return ans[dst] == INT_MAX ? -1 : ans[dst];
    }
};