class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        vector<int> vec;
        while (n)
        {
            int num = n % 10;
            vec.push_back(num);
            n = n / 10;
        }

        int sum = 0, product = 1;
        for (int i = 0; i < vec.size(); i++)
        {
            sum += vec[i];
            product *= vec[i];
        }

        return product - sum;
    }
};