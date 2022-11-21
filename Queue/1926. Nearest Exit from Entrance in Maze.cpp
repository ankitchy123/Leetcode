class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int row = entrance[0], col = entrance[1];
        maze[row][col] = '+';

        queue<array<int, 3>> q;
        q.push({row, col, 0});

        while (!q.empty())
        {
            auto [currRow, currCol, dis] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nextRow = currRow + dir[i].first, nextCol = currCol + dir[i].second;
                if (0 <= nextRow && nextRow < maze.size() && 0 <= nextCol && nextCol < maze[0].size() && maze[nextRow][nextCol] == '.')
                {

                    if (nextRow == 0 || nextRow == maze.size() - 1 || nextCol == 0 || nextCol == maze[0].size() - 1)
                    {
                        return dis + 1;
                    }

                    maze[nextRow][nextCol] = '+';
                    q.push({nextRow, nextCol, dis + 1});
                }
            }
        }
        return -1;
    }
};