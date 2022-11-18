class Solution
{
public:
    bool isUgly(int n)
    {
        if (n <= 0)
        {
            return false;
        }

        vector<int> vec = {2, 3, 5};
        for (int i = 0; i < 3; i++)
        {
            while (n % vec[i] == 0)
            {
                n /= vec[i];
            }
        }
        return n == 1;
    }
};