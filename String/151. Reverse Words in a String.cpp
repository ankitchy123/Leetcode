class Solution
{
public:
    void rev(string &s)
    {
        int n = s.length();
        for (int i = 0; i < n / 2; i++)
        {
            swap(s[i], s[n - i - 1]);
        }
    }

    string reverseWords(string s)
    {
        string ans = "";
        int n = s.size();
        int i = n - 1;
        string word = "";

        while (i >= 0)
        {
            if (s[i] == ' ')
            {
                if (word != "")
                {
                    rev(word);
                    ans += word;
                    ans += " ";
                }
                word = "";
                i--;
                while (i >= 0 && s[i] == ' ')
                {
                    i--;
                }
            }
            else
            {
                word += s[i];
                i--;
            }
        }
        if (word != "")
        {
            cout << word;
            rev(word);
            ans += word;
        }
        else
        {
            ans.pop_back();
        }
        return ans;
    }
};