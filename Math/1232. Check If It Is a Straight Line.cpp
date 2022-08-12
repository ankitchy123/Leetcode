class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        int m = (coordinates[1][1] - coordinates[0][1]);
        int n = (coordinates[1][0] - coordinates[0][0]);

        for (int i = 1; i < coordinates.size() - 1; i++)
        {
            if ((coordinates[i + 1][1] - coordinates[i][1]) * n != (coordinates[i + 1][0] - coordinates[i][0]) * m)
            {
                return false;
            }
        }

        return true;
    }
};