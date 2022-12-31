class Solution
{
public:
    int solve(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0 || grid[i][j] == 1)
        {
            return 0;
        }

        if (i == 0 && j == 0)
        {
            return 1;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int temp1 = solve(grid, i - 1, j, dp);
        int temp2 = solve(grid, i, j - 1, dp);
        return dp[i][j] = temp1 + temp2;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return solve(grid, grid.size() - 1, grid[0].size() - 1, dp);
    }
};