class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }

        string ans = "";
        int skip = 2 * (numRows - 1);
        for (int i = 0; i < numRows; i++)
        {
            int ind = i;
            while (ind < s.size())
            {
                ans += s[ind];
                if (i != 0 && i != numRows - 1)
                {
                    int next = skip - 2 * i;
                    int ind2 = ind + next;
                    if (ind2 < s.size())
                    {
                        ans += s[ind2];
                    }
                }
                ind += skip;
            }
        }
        return ans;
    }
};