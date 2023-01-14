class Solution
{
public:
    vector<int> vec;
    int find(int x)
    {
        if (vec[x] == x)
        {
            return x;
        }
        return vec[x] = find(vec[x]);
    }
    void Union(int x, int y)
    {
        x = find(x);
        y = find(y);

        if (x == y)
        {
            return;
        }

        if (x < y)
        {
            vec[y] = x;
        }
        else
        {
            vec[x] = y;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        for (int i = 0; i < 26; i++)
        {
            vec.push_back(i);
        }

        for (int i = 0; i < s1.size(); i++)
        {
            Union(s1[i] - 'a', s2[i] - 'a');
        }

        for (int i = 0; i < baseStr.size(); i++)
        {
            baseStr[i] = (find(baseStr[i] - 'a') + 'a');
        }
        return baseStr;
    }
};