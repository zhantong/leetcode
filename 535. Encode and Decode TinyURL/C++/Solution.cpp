class Solution {
public:
    unordered_map<string, string> short2long;
    unordered_map<string, string> long2short;

    string generate(int n) {
        string pool = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        string result = "";
        for (int i = 0; i < n; i++) {
            result += pool[rand() % pool.length()];
        }
        return result;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        while (long2short.find(longUrl) == long2short.end()) {
            string shortUrl = "http://tinyurl.com/" + generate(6);
            if (short2long.find(shortUrl) == short2long.end()) {
                short2long[shortUrl] = longUrl;
                long2short[longUrl] = shortUrl;
            }
        }
        return long2short[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return short2long[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));