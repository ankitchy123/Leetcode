class Solution
{
public:
    int minOperations(int n)
    {
        if (n <= 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        int temp = 1;
        while (temp * 2 < n)
        {
            temp *= 2;
        }

        int temp2 = temp * 2 - n;
        temp = n - temp;

        int low = minOperations(temp);
        int high = minOperations(temp2);
        return min(low, high) + 1;
    }
};