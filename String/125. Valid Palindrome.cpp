class Solution
{
public:
    bool isPalindrome(string s)
    {
        int j = 0;

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (c >= 'A' && c <= 'Z')
            {
                c += 32;
            }

            if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'))
            {
                s[j] = c;
                j++;
            }
        }
        s = s.substr(0, j);

        int start = 0, end = j - 1;
        while (start <= end)
        {
            if (s[start] != s[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};