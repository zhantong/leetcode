class Solution:
    def judgePoint24(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        EPS = 0.001

        def back_trace(nums):
            if len(nums) == 1:
                return abs(nums[0] - 24) < EPS
            for i, a in enumerate(nums):
                for j, b in enumerate(nums[:i]):
                    candidates = [a + b, a - b, b - a, a * b]
                    if abs(a) > EPS:
                        candidates.append(b / a)
                    if abs(b) > EPS:
                        candidates.append(a / b)
                    del nums[i]
                    del nums[j]
                    for candidate in candidates:
                        nums.append(candidate)
                        if back_trace(nums):
                            return True
                        nums.pop()
                    nums.insert(j, b)
                    nums.insert(i, a)
            return False

        return back_trace(nums)
