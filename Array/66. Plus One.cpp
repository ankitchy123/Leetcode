class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size() - 1;
        int count = 0;
        for (int i = n; i >= 0; --i)
        {
            if (digits[i] == 9)
            {
                digits[i] = 0;
                count++;
            }
            else
            {
                digits[i] += 1;
                return digits;
            }
        }
        if (count == n + 1)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};