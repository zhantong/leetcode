class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        que = collections.deque()
        result = []
        for i, num in enumerate(nums):
            if que and que[0] == i - k:
                que.popleft()
            while que and nums[que[-1]] < num:
                que.pop()
            que.append(i)
            if i + 1 >= k:
                result.append(nums[que[0]])
        return result
