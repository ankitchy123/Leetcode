class Solution
{
public:
    string intToRoman(int num)
    {
        int divisor[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string maps[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int i = 12;
        string ans = "";
        while (num)
        {
            if (num >= divisor[i])
            {
                int x = num / divisor[i];
                while (x--)
                {
                    ans += maps[i];
                    num -= divisor[i];
                }
            }
            i--;
        }
        return ans;
    }
};