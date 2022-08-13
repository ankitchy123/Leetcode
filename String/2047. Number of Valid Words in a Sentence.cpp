class Solution
{
public:
    bool Valid(string s)
    {
        int count = 0, count2 = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '-')
            {
                count++;
                if (count >= 2)
                {
                    return false;
                }
            }
            if (s[i] == '!')
            {
                count2++;
                if (count2 >= 2)
                {
                    return false;
                }
            }
            if (s[i] >= '0' && s[i] <= '9')
            {
                return false;
            }
            else if ((s[i] == '.' || s[i] == '!' || s[i] == ',') && (i != s.size() - 1))
            {
                return false;
            }
            if (i == 0 || i == s.size() - 1)
            {
                if (s[i] == '-')
                    return false;
            }
            else if (s[i] == '-')
            {
                if (!(s[i - 1] <= 'z' && s[i + 1] >= 'a'))
                {
                    return false;
                }
            }
        }

        return true;
    }
    int countValidWords(string sentence)
    {
        int count = 0;
        string word = "";
        for (int i = 0; i < sentence.size(); i++)
        {
            if (sentence[i] == ' ')
            {
                if (word != "" && Valid(word))
                {
                    count++;
                }
                word = "";
                continue;
            }
            word += sentence[i];
        }
        if (word != "" && Valid(word))
        {
            count++;
        }
        return count;
    }
};