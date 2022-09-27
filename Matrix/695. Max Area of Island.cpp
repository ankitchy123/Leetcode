class Solution
{
public:
    int solve(vector<vector<int>> &grid, vector<vector<bool>> &vec, int i, int j)
    {
        int ans = 0;
        if (grid[i][j] == 1)
        {
            grid[i][j] = 0;
            ans++;
        }
        else
        {
            return 0;
        }

        if (i - 1 >= 0 && !vec[i - 1][j])
        {
            ans += solve(grid, vec, i - 1, j);
        }
        if (j - 1 >= 0 && !vec[i][j - 1])
        {
            ans += solve(grid, vec, i, j - 1);
        }
        if (i + 1 < grid.size() && !vec[i + 1][j])
        {
            ans += solve(grid, vec, i + 1, j);
        }
        if (j + 1 < grid[0].size() && !vec[i][j + 1])
        {
            ans += solve(grid, vec, i, j + 1);
        }
        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int ans = 0;
        vector<vector<bool>> vec(grid.size(), vector<bool>(grid[0].size(), false));

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1 && !vec[i][j])
                {
                    ans = max(ans, solve(grid, vec, i, j));
                }
            }
        }
        return ans;
    }
};