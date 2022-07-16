class Solution
{
public:
    int countPoints(string rings)
    {
        unordered_map<int, set<char>> m;

        for (int i = 0; i < rings.size(); i += 2)
        {
            m[rings[i + 1]].insert(rings[i]);
        }

        int ans = 0;
        for (int i = 0; i < m.size(); i++)
        {
            if (m[i].size() == 3)
            {
                ans++;
            }
        }

        return ans;
    }
};