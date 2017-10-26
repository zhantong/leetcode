class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        def combination(result, current, start, k, n):
            if k == 0 and n == 0:
                result.append(current[:])
            elif k > 0 and n > 0:
                for i in range(start, 10):
                    current.append(i)
                    combination(result, current, i + 1, k - 1, n - i)
                    current.pop()

        result = []
        combination(result, [], 1, k, n)
        return result
