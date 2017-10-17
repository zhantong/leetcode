class Solution(object):
    def maxEnvelopes(self, envelopes):
        """
        :type envelopes: List[List[int]]
        :rtype: int
        """
        envelopes.sort(key=lambda x: (x[0], -x[1]))
        dp = [0] * len(envelopes)
        current_length = 0
        for envelope in envelopes:
            low = 0
            high = current_length
            value = envelope[1]
            while low < high:
                mid = (low + high) // 2
                if dp[mid] == value:
                    low = mid
                    break
                if dp[mid] < value:
                    low = mid + 1
                else:
                    high = mid
            dp[low] = value
            if low == current_length:
                current_length += 1
        return current_length
