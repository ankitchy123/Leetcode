class Solution
{
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &k)
    {
        vector<vector<int>> ans;
        int x = k[0], y = k[1];
        vector<vector<bool>> q(8, vector<bool>(8, false));

        for (int i = 0; i < queens.size(); i++)
        {
            q[queens[i][0]][queens[i][1]] = true;
        }

        for (int i = x - 1; i >= 0; i--)
        {
            if (q[i][y])
            {
                ans.push_back({i, y});
                break;
            }
        }

        for (int i = x + 1; i < 8; i++)
        {
            if (q[i][y])
            {
                ans.push_back({i, y});
                break;
            }
        }

        for (int i = y - 1; i >= 0; i--)
        {
            if (q[x][i])
            {
                ans.push_back({x, i});
                break;
            }
        }

        for (int i = y + 1; i < 8; i++)
        {
            if (q[x][i])
            {
                ans.push_back({x, i});
                break;
            }
        }

        for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (q[i][j])
            {
                ans.push_back({i, j});
                break;
            }
        }

        for (int i = x - 1, j = y + 1; i >= 0 && j < 8; i--, j++)
        {
            if (q[i][j])
            {
                ans.push_back({i, j});
                break;
            }
        }

        for (int i = x + 1, j = y - 1; i < 8 && j >= 0; i++, j--)
        {
            if (q[i][j])
            {
                ans.push_back({i, j});
                break;
            }
        }

        for (int i = x + 1, j = y + 1; i < 8 && j < 8; i++, j++)
        {
            if (q[i][j])
            {
                ans.push_back({i, j});
                break;
            }
        }
        return ans;
    }
};