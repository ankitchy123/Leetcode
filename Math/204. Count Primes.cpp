class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> vec(n, true);
        for (int p = 2; p * p < n; p++)
        {
            if (vec[p] == true)
            {
                for (int i = p * p; i < n; i += p)
                {
                    vec[i] = false;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++)
        {
            if (vec[i])
            {
                count++;
            }
        }
        return count;
    }
};