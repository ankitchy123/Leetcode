class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int count = 1;
        int j = 0, i;
        for (i = 1; i < chars.size(); i++)
        {
            if (chars[i - 1] == chars[i])
            {
                count++;
            }
            else
            {
                if (count > 1)
                {
                    chars[j++] = chars[i - 1];
                    string s = to_string(count);
                    for (int k = 0; k < s.size(); k++)
                    {
                        chars[j++] = s[k];
                    }
                }
                else
                {
                    chars[j++] = chars[i - 1];
                }
                count = 1;
            }
        }

        if (count > 1)
        {
            chars[j++] = chars[i - 1];
            string s = to_string(count);
            for (int k = 0; k < s.size(); k++)
            {
                chars[j++] = s[k];
            }
        }
        else
        {
            chars[j++] = chars[i - 1];
        }
        int n = chars.size();
        while (j < n)
        {
            j++;
            chars.pop_back();
        }
        return chars.size();
    }
};