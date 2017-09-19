class Solution:
    def findLongestChain(self, pairs):
        """
        :type pairs: List[List[int]]
        :rtype: int
        """
        pairs.sort(key=lambda x: x[1])
        result = 1
        current = pairs[0][1]
        for pair in pairs:
            if pair[0] > current:
                current = pair[1]
                result += 1
        return result
