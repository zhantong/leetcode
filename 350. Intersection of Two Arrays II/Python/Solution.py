class Solution:
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        nums1_dict = {}
        for num in nums1:
            nums1_dict[num] = nums1_dict.get(num, 0) + 1
        result = []
        for num in nums2:
            if num in nums1_dict and nums1_dict[num] != 0:
                result.append(num)
                nums1_dict[num] -= 1
        return result
