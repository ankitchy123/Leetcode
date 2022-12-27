class Solution
{
public:
    string arrangeWords(string text)
    {
        map<int, vector<string>> mp;
        string word;
        int len = 0;
        for (int i = 0; i < text.size(); i++)
        {
            if (text[i] == ' ')
            {
                mp[len].push_back(word);
                word = "";
                len = 0;
            }
            else
            {
                len += 1;
                word += tolower(text[i]);
            }
        }
        mp[len].push_back(word);
        text = "";
        for (auto i : mp)
        {
            for (int j = 0; j < i.second.size(); j++)
            {
                text += i.second[j];
                text += " ";
            }
        }
        text.pop_back();

        text[0] = toupper(text[0]);
        return text;
    }
};