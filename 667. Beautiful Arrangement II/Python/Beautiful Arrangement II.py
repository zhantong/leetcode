class Solution:
    def constructArray(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[int]
        """
        result = []
        i = 1
        j = n
        while i <= j:
            if k > 0:
                if k % 2:
                    result.append(i)
                    i += 1
                else:
                    result.append(j)
                    j -= 1
                k -= 1
            else:
                result.append(i)
                i += 1
        return result
