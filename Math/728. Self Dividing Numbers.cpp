class Solution
{
public:
    bool isDivisible(int num)
    {
        int n = num;
        while (num)
        {
            int x = num % 10;
            if (x == 0)
            {
                return false;
            }

            if (n % x != 0)
            {
                return false;
            }
            num /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> vec;
        for (int i = left; i <= right; i++)
        {
            if (isDivisible(i))
            {
                vec.push_back(i);
            }
        }

        return vec;
    }
};