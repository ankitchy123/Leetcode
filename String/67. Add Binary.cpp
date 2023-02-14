class Solution
{
public:
    string addBinary(string a, string b)
    {
        string s = "";
        string c = "0";
        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 && j >= 0)
        {
            if (c == "0")
            {
                if (a[i] == '0')
                {
                    if (b[j] == '0')
                    {
                        c = "0";
                        s += "0";
                    }
                    else
                    {
                        c = "0";
                        s += "1";
                    }
                }
                else
                {
                    if (b[j] == '0')
                    {
                        c = "0";
                        s += "1";
                    }
                    else
                    {
                        c = "1";
                        s += "0";
                    }
                }
            }
            else
            {
                if (a[i] == '0')
                {
                    if (b[j] == '0')
                    {
                        c = "0";
                        s += "1";
                    }
                    else
                    {
                        c = "1";
                        s += "0";
                    }
                }
                else
                {
                    if (b[j] == '0')
                    {
                        c = "1";
                        s += "0";
                    }
                    else
                    {
                        c = "1";
                        s += "1";
                    }
                }
            }

            i--;
            j--;
        }

        while (i >= 0)
        {
            if (c == "1")
            {
                if (a[i] == '1')
                {
                    c = "1";
                    s += "0";
                }
                else
                {
                    c = "0";
                    s += "1";
                }
            }
            else
            {
                if (a[i] == '1')
                {
                    c = "0";
                    s += "1";
                }
                else
                {
                    c = "0";
                    s += "0";
                }
            }

            i--;
        }
        while (j >= 0)
        {
            if (c == "1")
            {
                if (b[j] == '1')
                {
                    c = "1";
                    s += "0";
                }
                else
                {
                    c = "0";
                    s += "1";
                }
            }
            else
            {
                if (b[j] == '1')
                {
                    c = "0";
                    s += "1";
                }
                else
                {
                    c = "0";
                    s += "0";
                }
            }

            j--;
        }

        if (c == "1")
        {
            s += c;
        }

        reverse(s.begin(), s.end());
        return s;
    }
};