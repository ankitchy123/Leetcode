class Solution
{
public:
    bool solve(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited)
    {
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
        {
            return true;
        }
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || visited[i][j])
        {
            return false;
        }

        visited[i][j] = true;
        bool ans = false;
        if (grid[i][j] == 1)
        {
            if (j - 1 >= 0 && (grid[i][j - 1] == 1 || grid[i][j - 1] == 4 || grid[i][j - 1] == 6))
            {
                ans |= solve(grid, i, j - 1, visited);
            }
            if (j + 1 < grid[0].size() && (grid[i][j + 1] == 1 || grid[i][j + 1] == 3 || grid[i][j + 1] == 5))
            {
                ans |= solve(grid, i, j + 1, visited);
            }
        }
        else if (grid[i][j] == 2)
        {
            if (i + 1 < grid.size() && (grid[i + 1][j] == 2 || grid[i + 1][j] == 5 || grid[i + 1][j] == 6))
            {
                ans |= solve(grid, i + 1, j, visited);
            }
            if (i - 1 >= 0 && (grid[i - 1][j] == 2 || grid[i - 1][j] == 3 || grid[i - 1][j] == 4))
            {
                ans |= solve(grid, i - 1, j, visited);
            }
        }
        else if (grid[i][j] == 3)
        {
            if (i + 1 < grid.size() && (grid[i + 1][j] == 6 || grid[i + 1][j] == 5 || grid[i + 1][j] == 2))
            {
                ans |= solve(grid, i + 1, j, visited);
            }
            if (j - 1 >= 0 && (grid[i][j - 1] == 1 || grid[i][j - 1] == 4 || grid[i][j - 1] == 6))
            {
                ans |= solve(grid, i, j - 1, visited);
            }
        }
        else if (grid[i][j] == 4)
        {
            if (i + 1 < grid.size() && (grid[i + 1][j] == 6 || grid[i + 1][j] == 5 || grid[i + 1][j] == 2))
            {
                ans |= solve(grid, i + 1, j, visited);
            }
            if (j + 1 < grid[0].size() && (grid[i][j + 1] == 1 || grid[i][j + 1] == 5 || grid[i][j + 1] == 3))
            {
                ans |= solve(grid, i, j + 1, visited);
            }
        }
        else if (grid[i][j] == 5)
        {
            if (i - 1 >= 0 && (grid[i - 1][j] == 3 || grid[i - 1][j] == 4 || grid[i - 1][j] == 2))
            {
                ans |= solve(grid, i - 1, j, visited);
            }
            if (j - 1 >= 0 && (grid[i][j - 1] == 1 || grid[i][j - 1] == 4 || grid[i][j - 1] == 6))
            {
                ans |= solve(grid, i, j - 1, visited);
            }
        }
        else if (grid[i][j] == 6)
        {
            if (i - 1 >= 0 && (grid[i - 1][j] == 4 || grid[i - 1][j] == 3 || grid[i - 1][j] == 2))
            {
                ans |= solve(grid, i - 1, j, visited);
            }
            if (j + 1 < grid[0].size() && (grid[i][j + 1] == 1 || grid[i][j + 1] == 3 || grid[i][j + 1] == 5))
            {
                ans |= solve(grid, i, j + 1, visited);
            }
        }
        visited[i][j] = false;
        return ans;
    }
    bool hasValidPath(vector<vector<int>> &grid)
    {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        return solve(grid, 0, 0, visited);
    }
};