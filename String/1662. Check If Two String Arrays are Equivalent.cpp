class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string s1 = "";
        string s2 = "";
        int i = 0;
        int j = 0;

        while (i < word1.size() && j < word2.size())
        {
            s1 += word1[i];
            s2 += word2[j];
            i++;
            j++;
        }
        while (i < word1.size())
        {
            s1 += word1[i];
            i++;
        }
        while (j < word2.size())
        {
            s2 += word2[j];
            j++;
        }
        if (s1 == s2)
        {
            return true;
        }

        return false;
    }
};