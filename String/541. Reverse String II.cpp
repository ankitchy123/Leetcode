class Solution
{
public:
    string reverseStr(string s, int n)
    {
        for (int i = 0; i < s.size(); i += 2 * n)
        {
            int j = i, k = i + n - 1;
            if (k > s.size() - 1)
            {
                k = s.size() - 1;
            }
            while (j <= k)
            {
                swap(s[j], s[k]);
                j++;
                k--;
            }
        }
        return s;
    }
};