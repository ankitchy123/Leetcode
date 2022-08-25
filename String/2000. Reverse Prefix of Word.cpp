class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        int i = 0;
        while (word[i] != ch)
        {
            i++;
            if (i > word.size())
            {
                return word;
            }
        }

        for (int j = 0; j <= i / 2; j++)
        {
            char temp = word[j];
            cout << temp;
            word[j] = word[i - j];
            word[i - j] = temp;
        }
        return word;
    }
};