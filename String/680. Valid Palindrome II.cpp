class Solution
{
public:
    bool check(string s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    bool validPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;
        int count = 0;
        while (i <= j)
        {
            if (s[i] != s[j])
            {
                return check(s, i, j - 1) || check(s, i + 1, j);
            }
            i++;
            j--;
        }

        return true;
    }
};