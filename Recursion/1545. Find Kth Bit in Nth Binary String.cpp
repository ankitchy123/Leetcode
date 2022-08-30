class Solution
{
public:
    string s = "0";

    string invert(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                s[i] = '1';
            }
            else
            {
                s[i] = '0';
            }
        }
        return s;
    }

    string reverse(string s)
    {
        for (int i = 0; i < s.size() / 2; i++)
        {
            swap(s[i], s[s.size() - 1 - i]);
        }
        return s;
    }

    char findKthBit(int n, int k)
    {
        if (n == 1)
        {
            int i = 0;
            while (i < k)
            {
                i++;
            }
            return s[i - 1];
        }
        string temp = invert(s);
        string temp2 = reverse(temp);
        s += "1" + temp2;
        return findKthBit(n - 1, k);
    }
};