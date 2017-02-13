class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        i = 0
        j = len(numbers) - 1
        while i < j:
            two_sum = numbers[i] + numbers[j]
            if two_sum == target:
                break
            if two_sum > target:
                j -= 1
            else:
                i += 1
        return [i + 1, j + 1]
