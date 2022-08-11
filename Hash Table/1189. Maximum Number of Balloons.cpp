class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        map<char, int> mp;
        for (int i = 0; i < text.size(); i++)
        {
            char c = text[i];
            if (c == 'b' || c == 'a' || c == 'l' || c == 'o' || c == 'n')
            {
                mp[c]++;
            }
        }

        int ans = 0;
        ans = min(mp['b'], min(mp['a'], min(mp['l'] / 2, min(mp['o'] / 2, mp['n']))));
        return ans;
    }
};