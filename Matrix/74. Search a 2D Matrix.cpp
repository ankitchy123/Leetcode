class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int s = 0;
        int e = matrix.size() - 1;
        int mid;
        while (s <= e)
        {
            mid = s + (e - s) / 2;
            if (matrix[mid][0] > target)
            {
                e = mid - 1;
            }
            else if (matrix[mid][0] < target)
            {
                if (matrix[mid][matrix[0].size() - 1] >= target)
                {
                    break;
                }
                else
                {
                    s = mid + 1;
                }
            }
            else
            {
                break;
            }
        }

        s = 0;
        e = matrix[0].size() - 1;
        int mid2;
        while (s <= e)
        {
            mid2 = s + (e - s) / 2;
            if (matrix[mid][mid2] == target)
            {
                return true;
            }
            else if (matrix[mid][mid2] < target)
            {
                s = mid2 + 1;
            }
            else
            {
                e = mid2 - 1;
            }
        }
        return false;
    }
};