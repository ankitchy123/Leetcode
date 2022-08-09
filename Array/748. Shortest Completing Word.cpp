class Solution
{
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words)
    {
        int m1[26] = {};

        for (int i = 0; i < licensePlate.size(); i++)
        {
            char c = licensePlate[i];
            if ((c >= 'a' && c <= 'z'))
            {
                m1[c - 'a']++;
            }
            else if (c >= 'A' && c <= 'Z')
            {
                m1[c - 'A']++;
            }
        }

        int min = -1;
        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            int m2[26] = {};

            for (int j = 0; j < word.size(); j++)
            {
                m2[word[j] - 'a']++;
            }

            bool complete = true;
            for (int j = 0; j < 26; j++)
            {
                if (m1[j] > m2[j])
                {
                    complete = false;
                }
            }

            if (complete && (min == -1 || word.size() < words[min].size()))
            {
                min = i;
            }
        }

        return words[min];
    }
};