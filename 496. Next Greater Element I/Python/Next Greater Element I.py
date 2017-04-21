class Solution(object):
    def nextGreaterElement(self, findNums, nums):
        """
        :type findNums: List[int]
        :type nums: List[int]
        :rtype: List[int]
        """
        result = []
        if not findNums:
            return result
        num_max = max(nums)
        map = [-1] * (num_max + 1)
        for index, num in enumerate(nums):
            map[num] = index
        for find_num in findNums:
            if find_num >= num_max:
                result.append(-1)
            else:
                current_index = map[find_num] + 1
                while current_index < len(nums):
                    if nums[current_index] > find_num:
                        result.append(nums[current_index])
                        break
                    current_index += 1
                if current_index == len(nums):
                    result.append(-1)
        return result
