class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        def combination(candidates, target, start, result, current):
            if target < 0:
                return
            if target == 0:
                result.append(current[:])
                return
            for i in range(start, len(candidates)):
                if i > start and candidates[i] == candidates[i - 1]:
                    continue
                current.append(candidates[i])
                combination(candidates, target - candidates[i], i + 1, result, current)
                current.pop()

        result = []
        candidates.sort()
        combination(candidates, target, 0, result, [])
        return result
