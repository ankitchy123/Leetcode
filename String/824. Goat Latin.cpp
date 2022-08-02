class Solution
{
public:
    string toGoatLatin(string sentence)
    {
        string ans = "";
        string a = "a";
        char c = sentence[0];
        if ((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'))
        {
            ans += c;
        }

        for (int i = 1; i < sentence.size(); i++)
        {
            if (sentence[i] == ' ')
            {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                {
                    ans += "ma" + a + " ";
                }
                else
                {
                    ans += c;
                    ans += "ma" + a + " ";
                }
                a += "a";

                c = sentence[i + 1];
                if ((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'))
                {
                    ans += c;
                }
                i++;
                continue;
            }
            else
            {
                ans += sentence[i];
            }
        }
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            ans += "ma" + a;
        }
        else
        {
            ans += c;
            ans += "ma" + a;
        }
        return ans;
    }
};