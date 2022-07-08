class Solution
{
public:
    int minimumSum(int num)
    {
        vector<int> num1;
        while (num)
        {
            int n = num % 10;
            num1.push_back(n);

            num = num / 10;
        }

        sort(num1.begin(), num1.end());

        num1[0] = num1[0] * 10;
        num1[1] = num1[1] * 10;

        return num1[0] + num1[1] + num1[2] + num1[3];
    }
};