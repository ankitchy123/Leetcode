class Solution
{
public:
    int solve(vector<vector<int>> &grid, int i, int j, int &count)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1)
        {
            return 0;
        }

        if (grid[i][j] == 2)
        {
            if (count == -1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        count--;
        grid[i][j] = -1;
        int total = solve(grid, i + 1, j, count) + solve(grid, i - 1, j, count) + solve(grid, i, j + 1, count) + solve(grid, i, j - 1, count);
        count++;
        grid[i][j] = 0;
        return total;
    }
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int count = 0, x, y;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 0)
                {
                    count++;
                }
                else if (grid[i][j] == 1)
                {
                    x = i;
                    y = j;
                }
            }
        }
        return solve(grid, x, y, count);
    }
};