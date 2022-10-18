class Solution
{
public:
    bool solve(vector<vector<char>> &board, string word, int i, int j, int k)
    {
        if (k == word.size())
        {
            return true;
        }

        if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0)
        {
            return false;
        }

        if (word[k] != board[i][j])
        {
            return false;
        }
        board[i][j] = '.';
        bool ans1 = solve(board, word, i + 1, j, k + 1);
        bool ans2 = solve(board, word, i - 1, j, k + 1);
        bool ans3 = solve(board, word, i, j + 1, k + 1);
        bool ans4 = solve(board, word, i, j - 1, k + 1);

        board[i][j] = word[k];
        return ans1 || ans2 || ans3 || ans4;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    if (solve(board, word, i, j, 0))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};