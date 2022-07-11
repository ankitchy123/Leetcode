class Solution
{
public:
    string decodeMessage(string key, string message)
    {
        unordered_map<char, int> m;

        char c = 'a';

        for (int i = 0; i < key.size(); i++)
        {
            if (key[i] == ' ')
            {
                continue;
            }
            else if (!m[key[i]])
            {
                m[key[i]] = c++;
            }
        }

        string ans = "";
        for (int i = 0; i < message.size(); i++)
        {
            if (message[i] == ' ')
            {
                ans += " ";
                continue;
            }

            ans += m[message[i]];
        }

        return ans;
    }
};