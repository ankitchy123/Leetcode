class Solution
{
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        map<int, int> mp;
        for (int i = 0; i < brokenLetters.size(); i++)
        {
            mp[brokenLetters[i]] = 1;
        }

        int count = 0;
        bool flag = true;
        for (int i = 0; i < text.size(); i++)
        {
            if (text[i] == ' ')
            {
                if (flag)
                {
                    count++;
                }
                flag = true;
            }

            if (mp[text[i]] == 1)
            {
                flag = false;
            }
        }
        if (flag)
        {
            count++;
        }

        return count;
    }
};