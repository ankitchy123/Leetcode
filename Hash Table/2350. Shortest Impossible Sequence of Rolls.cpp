class Solution
{
public:
    int shortestSequence(vector<int> &rolls, int k)
    {
        map<int, int> mp;
        int ans = 1;
        for (int i = 0; i < rolls.size(); i++)
        {
            mp[rolls[i]]++;
            if (mp.size() == k)
            {
                mp.clear();
                ans++;
            }
        }
        return ans;
    }
};