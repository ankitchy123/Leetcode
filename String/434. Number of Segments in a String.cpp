class Solution
{
public:
    int countSegments(string s)
    {
        int count = 0;
        string word = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                if (word != "")
                {
                    count++;
                    word = "";
                }
                continue;
            }

            word += s[i];
        }
        if (word != "")
        {
            count++;
        }
        return count;
    }
};