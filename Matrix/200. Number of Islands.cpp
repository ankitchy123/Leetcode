class Solution
{
public:
    void solve(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &visited)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || visited[i][j] || grid[i][j] == '0')
        {
            return;
        }

        visited[i][j] = true;
        solve(grid, i - 1, j, visited);
        solve(grid, i + 1, j, visited);
        solve(grid, i, j - 1, visited);
        solve(grid, i, j + 1, visited);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    ans++;
                    solve(grid, i, j, visited);
                }
            }
        }
        return ans;
    }
};