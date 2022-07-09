class Solution
{
    int n = 0;
    map<string, string> m;

public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        string str = "http://tinyurl.com" + to_string(n);
        n++;
        m[str] = longUrl;
        return str;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));