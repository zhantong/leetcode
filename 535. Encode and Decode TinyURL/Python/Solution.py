class Codec:
    def __init__(self):
        self.short2long = {}
        self.long2short = {}

    def generate(self, n):
        pool = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789'
        return ''.join(random.choice(pool) for _ in range(n))

    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.

        :type longUrl: str
        :rtype: str
        """
        while longUrl not in self.long2short:
            short_url = 'http://tinyurl.com/' + self.generate(6)
            if short_url not in self.short2long:
                self.short2long[short_url] = longUrl
                self.long2short[longUrl] = short_url
        return self.long2short[longUrl]

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.

        :type shortUrl: str
        :rtype: str
        """
        return self.short2long[shortUrl]


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))
