class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<int> s1, s2;
        int i = 0, j = 0;

        while (i < s.size() && j < t.size())
        {
            if (s[i] == '#')
            {
                if (!s1.empty())
                {
                    s1.pop();
                }
            }
            else
            {
                s1.push(s[i]);
            }

            if (t[j] == '#')
            {
                if (!s2.empty())
                {
                    s2.pop();
                }
            }
            else
            {
                s2.push(t[j]);
            }

            i++;
            j++;
        }

        while (i < s.size())
        {
            if (s[i] == '#')
            {
                if (!s1.empty())
                {
                    s1.pop();
                }
            }
            else
            {
                s1.push(s[i]);
            }
            i++;
        }

        while (j < t.size())
        {
            if (t[j] == '#')
            {
                if (!s2.empty())
                {
                    s2.pop();
                }
            }
            else
            {
                s2.push(t[j]);
            }
            j++;
        }

        if (s1 == s2)
        {
            return true;
        }
        return false;
    }
};