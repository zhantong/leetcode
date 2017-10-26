class Solution(object):
    def findRotateSteps(self, ring, key):
        """
        :type ring: str
        :type key: str
        :rtype: int
        """
        ring_length = len(ring)
        key_length = len(key)
        dp = [[0] * ring_length for _ in range(key_length + 1)]
        index_same = {}
        for item in key:
            if item not in index_same:
                index_same[item] = [i for i in range(ring_length) if item == ring[i]]
        for key_index in range(key_length - 1, -1, -1):
            for ring_index in range(ring_length):
                dp[key_index][ring_index] = sys.maxsize
                for i in index_same[key[key_index]]:
                    clock_step = abs(ring_index - i)
                    min_step = min(clock_step, ring_length - clock_step)
                    dp[key_index][ring_index] = min(
                        dp[key_index][ring_index], min_step + dp[key_index + 1][i])
        return dp[0][0] + key_length
