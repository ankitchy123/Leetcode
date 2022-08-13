class Solution
{
public:
    string generateTheString(int n)
    {
        string s = "";
        if (n % 2 == 0)
        {
            int i = 0;
            while (i < n - 1)
            {
                s += "a";
                i++;
            }
            s += "b";
        }
        else
        {
            int i = 0;
            while (i <= n - 1)
            {
                s += "a";
                i++;
            }
        }

        return s;
    }
};