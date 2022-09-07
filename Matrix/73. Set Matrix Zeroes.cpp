class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        map<int, bool> mp1;
        map<int, bool> mp2;

        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    mp1[i] = true;
                    mp2[j] = true;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mp1[i] || mp2[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// OR

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        bool row = false, column = false;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;

                    if (i == 0)
                    {
                        row = true;
                    }
                    if (j == 0)
                    {
                        column = true;
                    }
                }
            }
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (row)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[0][i] = 0;
            }
        }

        if (column)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};