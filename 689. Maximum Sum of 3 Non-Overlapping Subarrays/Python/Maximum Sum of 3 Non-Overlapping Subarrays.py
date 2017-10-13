class Solution:
    def maxSumOfThreeSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        length = len(nums)
        left_sums = []
        temp = 0
        left_sums.append(temp)
        for num in nums:
            temp += num
            left_sums.append(temp)
        index_left = [0] * length
        current_max = 0
        for i in range(k - 1, length):
            if left_sums[i + 1] - left_sums[i + 1 - k] > current_max:
                index_left[i] = i + 1 - k
                current_max = left_sums[i + 1] - left_sums[i + 1 - k]
            else:
                index_left[i] = index_left[i - 1]
        index_right = [0] * length
        current_max = 0
        for i in range(length - k, -1, -1):
            if left_sums[i + k] - left_sums[i] >= current_max:
                index_right[i] = i
                current_max = left_sums[i + k] - left_sums[i]
            else:
                index_right[i] = index_right[i + 1]
        the_max = 0
        result = [0] * 3
        for i in range(k, length - 2 * k + 1):
            left = index_left[i - 1]
            right = index_right[i + k]
            current_max = left_sums[left + k] - left_sums[left] + left_sums[i + k] - left_sums[i] + left_sums[
                right + k] - left_sums[right]
            if current_max > the_max:
                result = [left, i, right]
                the_max = current_max
        return result
