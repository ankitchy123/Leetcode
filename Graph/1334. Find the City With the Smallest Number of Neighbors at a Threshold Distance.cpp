class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> mat(n, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < n; i++)
        {
            mat[i][i] = 0;
        }
        for (int i = 0; i < edges.size(); i++)
        {
            mat[edges[i][0]][edges[i][1]] = edges[i][2];
            mat[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (mat[i][j] > mat[i][k] + mat[k][j])
                    {
                        mat[i][j] = mat[i][k] + mat[k][j];
                    }
                }
            }
        }

        int num = INT_MAX, ans = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }
                if (mat[i][j] <= distanceThreshold)
                {
                    count++;
                }
            }
            if (count < num)
            {
                num = count;
                ans = i;
            }
        }
        return ans;
    }
};