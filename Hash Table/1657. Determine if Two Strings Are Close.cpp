class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.size() != word2.size())
        {
            return false;
        }
        unordered_map<char, int> m1, m2;
        for (int i = 0; i < word1.size(); i++)
        {
            m1[word1[i]]++;
            m2[word2[i]]++;
        }

        vector<int> a, b;
        for (auto i : m1)
        {
            if (!m2[i.first])
            {
                return false;
            }
            a.push_back(i.second);
            b.push_back(m2[i.first]);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a == b)
        {
            return true;
        }
        return false;
    }
};