class Solution
{
public:
    int shortestSequence(vector<int> &rolls, int k)
    {
        map<int, int> mp;
        int ans = 0, temp = 0;
        for (int i = 0; i < rolls.size(); i++)
        {
            mp[rolls[i]]++;
            if (mp[rolls[i]] == 1)
            {
                temp++;
            }
            if (temp == k)
            {
                temp = 0;
                mp.clear();
                ans++;
            }
        }
        return ans + 1;
    }
};