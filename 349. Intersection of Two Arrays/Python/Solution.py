class Solution:
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        nums1_set = set(nums1)
        intersect = set()
        for num in nums2:
            if num in nums1_set:
                intersect.add(num)
        return list(intersect)
