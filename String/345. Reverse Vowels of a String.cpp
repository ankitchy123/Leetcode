class Solution
{
    bool isVowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        else
            return false;
    }

public:
    string reverseVowels(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i <= j)
        {
            if (!isVowel(s[i]))
            {
                i++;
                continue;
            }
            if (!isVowel(s[j]))
            {
                j--;
                continue;
            }

            swap(s[i], s[j]);
            i++;
            j--;
        }

        return s;
    }
};