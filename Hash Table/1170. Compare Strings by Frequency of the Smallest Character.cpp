class Solution
{
public:
    int helper(string &word)
    {
        vector<int> arr(26, 0);
        for (char &ch : word)
        {
            arr[ch - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] != 0)
            {
                return arr[i];
            }
        }
        return -1;
    }

    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words)
    {
        vector<int> ans;
        vector<int> vec;

        for (int i = 0; i < words.size(); i++)
        {
            int num = helper(words[i]);
            vec.push_back(num);
        }

        sort(vec.begin(), vec.end());
        for (int i = 0; i < queries.size(); i++)
        {
            int freq = helper(queries[i]);

            int s = 0, e = vec.size() - 1;
            int num = vec.size();

            while (s <= e)
            {
                int mid = s + (e - s) / 2;
                if (vec[mid] > freq)
                {
                    num = mid;
                    e = mid - 1;
                }
                else
                {
                    s = mid + 1;
                }
            }
            ans.push_back(vec.size() - num);
        }

        return ans;
    }
};