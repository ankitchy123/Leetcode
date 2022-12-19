class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < edges.size(); i++)
        {
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> visited(n);
        visited[source] = true;
        queue<int> q;
        q.push(source);
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            if (curr == destination)
            {
                return true;
            }

            for (int i = 0; i < mp[curr].size(); i++)
            {
                if (!visited[mp[curr][i]])
                {
                    visited[mp[curr][i]] = true;
                    q.push(mp[curr][i]);
                }
            }
        }
        return false;
    }
};