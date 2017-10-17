class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        result.append([])
        for i, num in enumerate(nums):
            new_result = []
            for j in range(i + 1):
                for item in result:
                    new_item = item[:]
                    new_item.insert(j, num)
                    new_result.append(new_item)
            result = new_result
        return result
