class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int total = grid.size() + grid[0].size() + 1;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                }
                else
                {
                    grid[i][j] = total;
                    grid[i][j] = min(grid[i][j], min(i > 0 ? grid[i - 1][j] + 1 : total, j > 0 ? grid[i][j - 1] + 1 : total));
                }
            }
        }
        int ans = INT_MIN;
        for (int i = grid.size() - 1; i >= 0; i--)
        {
            for (int j = grid[0].size() - 1; j >= 0; j--)
            {
                grid[i][j] = min(grid[i][j], min(i < grid.size() - 1 ? grid[i + 1][j] + 1 : total, j < grid[0].size() - 1 ? grid[i][j + 1] + 1 : total));

                ans = max(ans, grid[i][j]);
            }
        }

        if (ans == 0 || ans == total)
        {
            return -1;
        }
        return ans;
    }
};