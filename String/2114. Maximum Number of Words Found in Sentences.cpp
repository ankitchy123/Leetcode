class Solution
{
public:
    int mostWordsFound(vector<string> &sentences)
    {
        int ans = 0;
        int words = 0;

        for (int i = 0; i < sentences.size(); i++)
        {
            for (int j = 0; j < sentences[i].size(); j++)
            {
                if (sentences[i][j] == ' ')
                {
                    words++;
                }
            }
            words++;
            ans = max(ans, words);
            words = 0;
        }
        return ans;
    }
};