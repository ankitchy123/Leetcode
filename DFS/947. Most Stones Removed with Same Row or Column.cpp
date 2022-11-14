class Solution
{
public:
    void solve(vector<int> &visited, vector<vector<int>> &stones, int ind)
    {
        visited[ind] = 1;
        for (int i = 0; i < stones.size(); i++)
        {
            if (!visited[i] && (stones[i][0] == stones[ind][0] || stones[i][1] == stones[ind][1]))
            {
                solve(visited, stones, i);
            }
        }
    }
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        vector<int> visited(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                count++;
                solve(visited, stones, i);
            }
        }

        return n - count;
    }
};