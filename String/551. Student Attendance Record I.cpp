class Solution
{
public:
    bool checkRecord(string s)
    {
        int count1 = 0, count2 = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'A')
            {
                count1++;
                count2 = 0;
                if (count1 >= 2)
                {
                    return false;
                }
            }
            else if (s[i] == 'L')
            {
                count2++;
                if (count2 >= 3)
                {
                    return false;
                }
            }
            else
            {
                count2 = 0;
            }
        }

        return true;
    }
};