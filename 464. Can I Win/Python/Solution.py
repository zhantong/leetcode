class Solution(object):
    def canIWin(self, maxChoosableInteger, desiredTotal):
        """
        :type maxChoosableInteger: int
        :type desiredTotal: int
        :rtype: bool
        """

        def to_key(choosed):
            result = 1
            for item in choosed:
                result <<= 1
                if item:
                    result |= 1
            return result

        def win(choosed, memory, total):
            key = to_key(choosed)
            if key in memory:
                return memory[key]
            for i in range(1, len(choosed)):
                if not choosed[i]:
                    choosed[i] = True
                    if total <= i or not win(choosed, memory, total - i):
                        memory[key] = True
                        choosed[i] = False
                        return True
                    choosed[i] = False
            memory[key] = False
            return False

        if desiredTotal == 0:
            return True
        if (1 + maxChoosableInteger) * maxChoosableInteger // 2 < desiredTotal:
            return False
        return win([False] * (maxChoosableInteger + 1), {}, desiredTotal)
