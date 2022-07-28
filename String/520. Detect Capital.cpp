class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        if (word[0] >= 'A' && word[0] <= 'Z')
        {
            int count = 0;

            for (int i = 0; i < word.size(); i++)
            {
                if (word[i] >= 'A' && word[i] <= 'Z')
                {
                    count++;
                }
            }

            if (count == 1 || count == word.size())
            {
                return true;
            }
        }
        else
        {
            int count = 0;
            for (int i = 0; i < word.size(); i++)
            {
                if (word[i] >= 'a' && word[i] <= 'z')
                {
                    count++;
                }
            }

            if (count == word.size())
            {
                return true;
            }
        }
        return false;
    }
};