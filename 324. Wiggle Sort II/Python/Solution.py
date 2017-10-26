class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        def kth_largest(nums, k):
            def partition(nums, low, high):
                pivot = nums[low]
                while low < high:
                    while low < high and nums[high] >= pivot:
                        high -= 1
                    nums[low] = nums[high]
                    while low < high and nums[low] <= pivot:
                        low += 1
                    nums[high] = nums[low]
                nums[low] = pivot
                return low

            random.shuffle(nums)
            #k -= 1
            low = 0
            high = len(nums) - 1
            while low < high:
                index = partition(nums, low, high)
                if index == k:
                    break
                elif index > k:
                    high = index - 1
                else:
                    low = index + 1
            return nums[k]

        copy = nums[:]
        medium = kth_largest(copy, len(copy) // 2)
        large_index = 1
        for i in range(len(copy)):
            if copy[i] > medium:
                nums[large_index] = copy[i]
                large_index += 2
        while large_index < len(copy):
            nums[large_index] = medium
            large_index += 2
        small_index = large_index - 1 if large_index == len(copy) else large_index - 3
        for i in range(len(copy)):
            if copy[i] < medium:
                nums[small_index] = copy[i]
                small_index -= 2
        while small_index >= 0:
            nums[small_index] = medium
            small_index -= 2
