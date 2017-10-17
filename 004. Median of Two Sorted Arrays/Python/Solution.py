class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)
        short_length = len(nums1)
        long_length = len(nums2)
        short_left = 0
        short_right = len(nums1)
        while short_left <= short_right:
            short_mid = (short_left + short_right) // 2
            long_mid = (short_length + long_length + 1) // 2 - short_mid
            if short_mid < short_length and nums1[short_mid] < nums2[long_mid - 1]:
                short_left = short_mid + 1
            elif short_mid > 0 and nums1[short_mid - 1] > nums2[long_mid]:
                short_right = short_mid - 1
            else:
                max_left = None
                if short_mid == 0:
                    max_left = nums2[long_mid - 1]
                elif long_mid == 0:
                    max_left = nums1[short_mid - 1]
                else:
                    max_left = max(nums1[short_mid - 1], nums2[long_mid - 1])
                if (short_length + long_length) % 2:
                    return max_left
                min_right = None
                if short_mid == short_length:
                    min_right = nums2[long_mid]
                elif long_mid == long_length:
                    min_right = nums1[short_mid]
                else:
                    min_right = min(nums1[short_mid], nums2[long_mid])
                return (max_left + min_right) / 2.0
