class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        set<pair<int, int>> row, col, box;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    if (row.count({i, board[i][j]}))
                    {
                        return false;
                    }
                    if (col.count({j, board[i][j]}))
                    {
                        return false;
                    }
                    int num = (i / 3) * 3 + (j / 3);
                    if (box.count({num, board[i][j]}))
                    {
                        return false;
                    }

                    row.insert({i, board[i][j]});
                    col.insert({j, board[i][j]});
                    box.insert({num, board[i][j]});
                }
            }
        }
        return true;
    }
};