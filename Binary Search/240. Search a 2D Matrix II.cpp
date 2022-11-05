class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = 0, col = matrix[0].size() - 1;
        while (row < matrix.size() && col >= 0)
        {
            int curr = matrix[row][col];
            if (curr == target)
            {
                return true;
            }
            else if (target > curr)
            {
                row++;
            }
            else
            {
                col--;
            }
        }
        return false;
    }
};