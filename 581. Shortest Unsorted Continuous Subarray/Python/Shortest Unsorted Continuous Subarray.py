class Solution:
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        the_min = sys.maxsize
        the_max = -sys.maxsize
        is_unsorted = False
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                the_max = max(the_max, nums[i])
                the_min = min(the_min, nums[i + 1])
                is_unsorted = True
        if not is_unsorted:
            return 0
        start = -1
        for i in range(len(nums)):
            if nums[i] > the_min:
                start = i
                break
        end = -1
        for i in range(len(nums) - 1, -1, -1):
            if nums[i] < the_max:
                end = i
                break
        return end - start + 1
