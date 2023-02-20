class Solution
{
public:
    bool isVowel(char x)
    {
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
        {
            return true;
        }
        return false;
    }

    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        vector<int> vec;
        vec.push_back(0);
        for (auto w : words)
        {
            if (isVowel(w[0]) && isVowel(w.back()))
            {
                vec.push_back(vec.back() + 1);
            }
            else
            {
                vec.push_back(vec.back());
            }
        }
        vector<int> ans;
        for (auto q : queries)
        {
            ans.push_back(vec[q[1] + 1] - vec[q[0]]);
        }
        return ans;
    }
};