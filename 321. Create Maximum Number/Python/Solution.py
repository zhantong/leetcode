class Solution(object):
    def maxNumber(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[int]
        """
        def max_number_length_k(nums, k):
            result = [0] * k
            index = 0
            length = len(nums)
            for i, num in enumerate(nums):
                while index > 0 and result[index - 1] < num and length - i >= k - (index - 1):
                    index -= 1
                if index < k:
                    result[index] = num
                    index += 1
            return result

        def merge(nums_1, nums_2):
            result = []
            i = 0
            j = 0
            while i < len(nums_1) and j < len(nums_2):
                if greater(nums_1, i, nums_2, j):
                    result.append(nums_1[i])
                    i += 1
                else:
                    result.append(nums_2[j])
                    j += 1
            if i == len(nums_1):
                result.extend(nums_2[j:])
            else:
                result.extend(nums_1[i:])
            return result

        def greater(nums_1, start_1, nums_2, start_2):
            while start_1 < len(nums_1) and start_2 < len(nums_2) and nums_1[start_1] == nums_2[start_2]:
                start_1 += 1
                start_2 += 1
            if start_1 == len(nums_1) and start_2 == len(nums_2):
                return True
            if start_1 == len(nums_1):
                return False
            if start_2 == len(nums_2):
                return True
            return nums_1[start_1] > nums_2[start_2]

        result = [0] * k
        for i in range(k + 1):
            if i <= len(nums1) and k - i <= len(nums2):
                current = merge(max_number_length_k(nums1, i), max_number_length_k(nums2, k - i))
                if greater(current, 0, result, 0):
                    result = current
        return result
