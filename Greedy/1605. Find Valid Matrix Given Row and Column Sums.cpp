class Solution
{
public:
    vector<vector<int>> restoreMatrix(vector<int> &row, vector<int> &col)
    {
        int m = row.size();
        int n = col.size();

        vector<vector<int>> ans(m, vector<int>(n, 0));
        int i = 0, j = 0;
        while (i < m && j < n)
        {
            if (row[i] < col[j])
            {
                ans[i][j] = row[i];
                col[j] -= row[i];
                i++;
            }
            else
            {
                ans[i][j] = col[j];
                row[i] -= col[j];
                j++;
            }
        }
        return ans;
    }
};