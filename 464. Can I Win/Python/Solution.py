class Solution(object):
    def canIWin(self, maxChoosableInteger, desiredTotal):
        """
        :type maxChoosableInteger: int
        :type desiredTotal: int
        :rtype: bool
        """

        def win(choosed, memory, total):
            if choosed in memory:
                return memory[choosed]
            for i in range(1, maxChoosableInteger + 1):
                if choosed & 1 << i == 0:
                    if total <= i or not win(choosed | 1 << i, memory, total - i):
                        memory[choosed] = True
                        return True
            memory[choosed] = False
            return False

        if desiredTotal == 0:
            return True
        if (1 + maxChoosableInteger) * maxChoosableInteger // 2 < desiredTotal:
            return False
        return win(0, {}, desiredTotal)
