class Solution
{
public:
    long long smallestNumber(long long num)
    {
        int sign = 1;
        if (num < 0)
        {
            sign = -1;
            num *= -1;
        }
        vector<int> vec(10, 0);
        while (num)
        {
            int temp = (num % 10);
            vec[temp]++;
            num /= 10;
        }

        if (sign > 0)
        {
            for (int i = 1; i <= 9; i++)
            {
                if (vec[i])
                {
                    num = i;
                    vec[i]--;
                    break;
                }
            }

            for (int i = 0; i <= 9; i++)
            {
                while (vec[i]--)
                {
                    num = (num * 10) + i;
                }
            }
        }
        else
        {
            for (int i = 9; i >= 1; i--)
            {
                if (vec[i])
                {
                    num = i;
                    vec[i]--;
                    break;
                }
            }

            for (int i = 9; i >= 0; i--)
            {
                while (vec[i]--)
                {
                    num = (num * 10) + i;
                }
            }
            num *= -1;
        }
        return num;
    }
};