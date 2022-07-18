class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }

        unsigned int rev = 0;
        int original = x;

        while (x)
        {
            rev = (rev * 10) + (x % 10);
            x /= 10;
        }

        if (rev == original)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};