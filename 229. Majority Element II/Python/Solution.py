class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if len(nums) < 2:
            return nums
        a = nums[0]
        b = nums[0]
        count_a = 0
        count_b = 0
        for num in nums:
            if num == a:
                count_a += 1
            elif num == b:
                count_b += 1
            elif count_a == 0:
                a = num
                count_a = 1
            elif count_b == 0:
                b = num
                count_b = 1
            else:
                count_a -= 1
                count_b -= 1
        if a == b:
            return [a]
        result = []
        if nums.count(a) > len(nums) // 3:
            result.append(a)
        if nums.count(b) > len(nums) // 3:
            result.append(b)
        return result
