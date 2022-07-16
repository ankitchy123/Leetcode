class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        vector<string> vec = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

        vector<string> vec2;
        for (int i = 0; i < words.size(); i++)
        {
            string str = "";
            for (int j = 0; j < words[i].size(); j++)
            {
                str += vec[words[i][j] - 97];
            }
            vec2.push_back(str);
        }
        map<string, int> m;

        for (int i = 0; i < vec2.size(); i++)
        {
            m[vec2[i]]++;
        }

        return m.size();
    }
};