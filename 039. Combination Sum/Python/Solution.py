class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        def combination(candidates, result, current, start, left):
            if left == 0:
                result.append(current[:])
            else:
                for i in range(start, len(candidates)):
                    candidate = candidates[i]
                    if candidate <= left:
                        current.append(candidate)
                        combination(candidates, result, current, i, left - candidate)
                        current.pop()

        result = []
        combination(candidates, result, [], 0, target)
        return result
