class Solution
{
public:
    bool check(string s)
    {
        int i = 0, n = s.size();
        int j = n - 1;
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

    string base(int n, int base)
    {
        string s = "";
        while (n)
        {
            int x = n % base;
            s += to_string(x);
            n /= base;
        }
        return s;
    }
    bool isStrictlyPalindromic(int n)
    {
        for (int i = 2; i <= n - 2; i++)
        {
            string s = base(n, i);
            if (!check(s))
            {
                return false;
            }
        }
        return true;
    }
};