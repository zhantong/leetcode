public class Codec {
    Map<String, String> short2long = new HashMap<>();
    Map<String, String> long2short = new HashMap<>();
    Random random = new Random();

    String generate(int n) {
        String pool = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < n; i++) {
            builder.append(pool.charAt(random.nextInt(pool.length())));
        }
        return builder.toString();
    }

    // Encodes a URL to a shortened URL.
    public String encode(String longUrl) {
        while (!long2short.containsKey(longUrl)) {
            String shortUrl = "http://tinyurl.com/" + generate(6);
            if (!short2long.containsKey(shortUrl)) {
                short2long.put(shortUrl, longUrl);
                long2short.put(longUrl, shortUrl);
            }
        }
        return long2short.get(longUrl);
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
        return short2long.get(shortUrl);
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));