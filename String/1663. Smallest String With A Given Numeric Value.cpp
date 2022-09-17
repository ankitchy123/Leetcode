class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        string s = "";
        s.append(n, ' ');

        for (int i = n - 1; i >= 0; i--)
        {
            s[i] = 96 + min(k - i, 26);
            k -= (s[i] - 96);
        }
        return s;
    }
};