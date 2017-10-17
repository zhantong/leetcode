class Solution(object):
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        sumABDict = {}
        for a in A:
            for b in B:
                sumAB = a + b
                if sumAB not in sumABDict:
                    sumABDict[sumAB] = 0
                sumABDict[sumAB] += 1
        result = 0
        for c in C:
            for d in D:
                sumCD = -c - d
                if sumCD in sumABDict:
                    result += sumABDict[sumCD]
        return result
