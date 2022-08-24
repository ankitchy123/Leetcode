class Solution
{
public:
    string thousandSeparator(int n)
    {
        if (n < 1000)
        {
            return to_string(n);
        }
        string s = "";
        int count = 0;
        while (n)
        {
            int x = n % 10;
            count++;
            s += to_string(x);
            n /= 10;
            if (n == 0)
            {
                break;
            }
            if (count % 3 == 0)
            {
                s += ".";
            }
        }
        reverse(s.begin(), s.end());
        return s;
    }
};