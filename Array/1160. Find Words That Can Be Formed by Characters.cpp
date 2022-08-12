class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        vector<int> vec(26, 0);
        for (int i = 0; i < chars.size(); i++)
        {
            vec[chars[i] - 'a']++;
        }

        int count = 0;
        for (int i = 0; i < words.size(); i++)
        {
            int temp = 0;
            vector<int> v(26, 0);

            string word = words[i];
            for (int j = 0; j < word.size(); j++)
            {
                v[word[j] - 'a']++;
            }

            for (int j = 0; j < 26; j++)
            {
                if (vec[j] >= v[j])
                {
                    temp += v[j];
                }
                else
                {
                    temp = 0;
                    break;
                }
            }

            count += temp;
        }

        return count;
    }
};