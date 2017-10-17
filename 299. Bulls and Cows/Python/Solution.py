class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        counts = [0] * 10
        bulls = 0
        cows = 0
        for a, b in zip(secret, guess):
            if a == b:
                bulls += 1
            else:
                if counts[ord(a) - ord('0')] < 0:
                    cows += 1
                counts[ord(a) - ord('0')] += 1
                if counts[ord(b) - ord('0')] > 0:
                    cows += 1
                counts[ord(b) - ord('0')] -= 1
        return '%dA%dB' % (bulls, cows)
