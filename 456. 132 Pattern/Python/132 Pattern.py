class Solution(object):
    def find132pattern(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) < 3:
            return False
        stack = []
        for num in nums:
            if not stack or stack[-1][0] > num:
                stack.append((num, num))
            elif stack[-1][0] < num:
                if stack[-1][1] > num:
                    return True
                the_min = stack[-1][0]
                stack.pop()
                while stack and stack[-1][1] <= num:
                    stack.pop()
                if stack and stack[-1][0] < num:
                    return True
                stack.append((the_min, num))
        return False
