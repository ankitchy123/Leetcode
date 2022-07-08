class Solution
{
public:
    string sortSentence(string s)
    {
        vector<string> vec(10, "");

        string word = "";
        int count = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                word.pop_back();
                vec[s[i - 1] - '0'] = word + " ";
                count++;
                word = "";
            }
            else
            {
                word += s[i];
            }
        }

        word.pop_back();
        vec[s[s.size() - 1] - '0'] = word + " ";
        count++;
        word = "";

        string ans = "";
        for (int i = 0; i <= count; i++)
        {
            ans += vec[i];
        }
        ans.pop_back();

        return ans;
    }
};