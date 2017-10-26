class Solution(object):
    def reversePairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        def merge(array, temp_array, low, mid, high):
            start1 = low
            end1 = mid
            start2 = mid + 1
            end2 = high
            k = low
            while start1 <= end1 and start2 <= end2:
                if array[start1] < array[start2]:
                    temp_array[k] = array[start1]
                    start1 += 1
                else:
                    temp_array[k] = array[start2]
                    start2 += 1
                k += 1
            while start1 <= end1:
                temp_array[k] = array[start1]
                start1 += 1
                k += 1
            while start2 <= end2:
                temp_array[k] = array[start2]
                start2 += 1
                k += 1
            for k in range(low, high + 1):
                array[k] = temp_array[k]

        def merge_sort(array, temp_array, low, high):
            if low >= high:
                return 0
            mid = (low + high) // 2
            count = merge_sort(nums, temp_array, low, mid) + \
                merge_sort(nums, temp_array, mid + 1, high)
            j = mid + 1
            for i in range(low, mid + 1):
                while j <= high and nums[i] / 2.0 > nums[j]:
                    j += 1
                count += j - (mid + 1)
            mid = (low + high) // 2
            merge(array, temp_array, low, mid, high)
            return count

        return merge_sort(nums, [0] * len(nums), 0, len(nums) - 1)
