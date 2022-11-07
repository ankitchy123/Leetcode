class Solution
{
public:
    int maximum69Number(int num)
    {
        string s = to_string(num);

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '6')
            {
                s[i] = '9';
                break;
            }
        }

        return stoi(s);
    }
};

// OR

class Solution
{
public:
    int maximum69Number(int num)
    {
        int n = num;
        int indexFirstSix = -1;
        int ind = 0;

        while (n > 0)
        {
            if (n % 10 == 6)
            {
                indexFirstSix = ind;
            }
            n /= 10;
            ind++;
        }
        return indexFirstSix == -1 ? num : num + 3 * (int)pow(10, indexFirstSix);
    }
};