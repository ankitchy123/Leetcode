class Solution
{
public:
    string reformatNumber(string num)
    {
        for (int i = 0; i < num.length(); i++)
        {
            if (num[i] == ' ' || num[i] == '-')
            {
                num.erase(i--, 1);
            }
        }

        int blocks = num.size() % 3 == 1 ? 4 : num.size() % 3;
        int count = 0, i = 0;

        string str = "";
        while (i < num.size() - blocks)
        {
            str += num[i];
            count++;
            if (count % 3 == 0 && count < num.size())
            {
                str += '-';
            }

            i++;
        }
        count = 0;
        while (i < num.size())
        {
            str += num[i];
            count++;
            if (count % 2 == 0 && i < num.size() - 1)
            {
                str += '-';
            }
            i++;
        }

        return str;
    }
};