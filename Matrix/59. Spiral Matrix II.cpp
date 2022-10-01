class Solution
{
public:
    vector<vector<int>> generateMatrix(int a)
    {
        vector<vector<int>> ans(a, vector<int>(a, -1));

        int temp = 1, dir = 1;
        int m = 0, n = a - 1, x = 0, y = a - 1;

        while (temp <= a * a)
        {
            if (dir == 1)
            {
                for (int i = x; i <= y; i++)
                {
                    ans[m][i] = temp++;
                }
                dir = 2;
                m++;
            }
            else if (dir == 2)
            {
                for (int i = m; i <= n; i++)
                {
                    ans[i][y] = temp++;
                }
                dir = 3;
                y--;
            }
            else if (dir == 3)
            {
                for (int i = y; i >= x; i--)
                {
                    ans[n][i] = temp++;
                }
                dir = 4;
                n--;
            }
            else
            {
                for (int i = n; i >= m; i--)
                {
                    ans[i][x] = temp++;
                }
                dir = 1;
                x++;
            }
        }
        return ans;
    }
};