class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int dir = 1;
        int m = 0, n = matrix.size() - 1, x = 0, y = matrix[0].size() - 1;
        vector<int> vec;
        while (m <= n && x <= y)
        {
            if (dir == 1)
            {
                for (int i = x; i <= y; i++)
                {
                    vec.push_back(matrix[m][i]);
                }
                dir = 2;
                m++;
            }
            else if (dir == 2)
            {
                for (int i = m; i <= n; i++)
                {
                    vec.push_back(matrix[i][y]);
                }
                dir = 3;
                y--;
            }
            else if (dir == 3)
            {
                for (int i = y; i >= x; i--)
                {
                    vec.push_back(matrix[n][i]);
                }
                dir = 4;
                n--;
            }
            else
            {
                for (int i = n; i >= m; i--)
                {
                    vec.push_back(matrix[i][x]);
                }
                dir = 1;
                x++;
            }
        }
        return vec;
    }
};