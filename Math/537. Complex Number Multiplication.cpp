class Solution
{
public:
    string complexNumberMultiply(string num1, string num2)
    {
        int a = 0, b = 0;
        int i = 0;
        int sign = 1;
        while (num1[i] != '+')
        {
            if (num1[i] == '-')
            {
                sign = -1;
                i++;
                continue;
            }
            a = (a * 10) + (num1[i] - '0');
            i++;
        }
        i++;
        a *= sign;
        sign = 1;

        while (num1[i] != 'i')
        {
            if (num1[i] == '-')
            {
                sign = -1;
                i++;
                continue;
            }
            b = (b * 10) + (num1[i] - '0');
            i++;
        }
        b *= sign;
        sign = 1;
        i = 0;

        int x = 0, y = 0;
        while (num2[i] != '+')
        {
            if (num2[i] == '-')
            {
                sign = -1;
                i++;
                continue;
            }
            x = (x * 10) + (num2[i] - '0');
            i++;
        }
        i++;
        x *= sign;
        sign = 1;

        while (num2[i] != 'i')
        {
            if (num2[i] == '-')
            {
                sign = -1;
                i++;
                continue;
            }
            y = (y * 10) + (num2[i] - '0');
            i++;
        }
        y *= sign;

        int n1 = (a * x) - (b * y);
        int n2 = b * x + a * y;
        string s1 = to_string(n1);
        string s2 = to_string(n2);
        s2 += "i";
        return s1 + "+" + s2;
    }
};