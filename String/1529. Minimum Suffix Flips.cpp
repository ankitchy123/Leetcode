class Solution
{
public:
    int minFlips(string target)
    {
        int i = 0;
        while (target[i] == '0')
        {
            i++;
        }
        if (i == target.size())
        {
            return 0;
        }
        int ans = 0;
        char prev = '0';
        while (i < target.size())
        {
            if (prev != target[i])
            {
                ans++;
                prev = target[i];
            }
            i++;
        }
        return ans;
    }
};