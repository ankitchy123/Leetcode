class Solution
{
public:
    vector<string> printVertically(string s)
    {
        vector<string> ans, vec;
        string word = "";
        int maxLen = INT_MIN;
        s += " ";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                vec.push_back(word);
                int len = word.size();
                maxLen = max(maxLen, len);
                word = "";
            }
            else
            {
                word += s[i];
            }
        }

        for (int i = 0; i < maxLen; i++)
        {
            for (int j = 0; j < vec.size(); j++)
            {
                if (i >= vec[j].length())
                {
                    word += " ";
                }
                else
                {
                    word += vec[j][i];
                }
            }
            int n = word.size() - 1;
            while (word[n] == ' ')
            {
                word.pop_back();
                n--;
            }
            ans.push_back(word);
            word = "";
        }
        return ans;
    }
};