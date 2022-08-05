class Solution
{
public:
    int longestPalindrome(string s)
    {
        map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }

        bool isOdd = false;
        int count = 0;

        for (auto &i : mp)
        {
            if (i.second % 2 == 1)
            {
                if (!isOdd)
                {
                    isOdd = true;
                    count += i.second;
                }
                else
                {
                    count += i.second - 1;
                }
            }
            else
            {
                count += i.second;
            }
        }

        return count;
    }
};